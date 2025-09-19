#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////
/*


*/

struct Bike : std::array<int, 2> {
    Bike() : std::array<int, 2>() {}
    void set_bi(int bi) {this->at(0) = bi;}
    void set_cost(int c) {this->at(1) = c;}
    int bi() {return this->at(0);}
    vector<int>& bike(vector<vector<int>>& bikes) const {return bikes[this->at(0)];}
    int cost() const {return this->at(1);}
};

struct Worker {
    int wi;
    vector<Bike> prefs;
    int offset = 0;

    Worker(vector<vector<int>>& workers, vector<vector<int>>& bikes, int wi) : wi(wi), prefs(bikes.size()) {
        for (int bi = 0; bi < bikes.size(); bi++) {
            prefs[bi].set_bi(bi);
            prefs[bi].set_cost(
                std::abs(workers[wi][0] - bikes[bi][0]) + std::abs(workers[wi][1] - bikes[bi][1])
            );
        }
        std::sort(prefs.begin(), prefs.end(), [](auto &lhs, auto& rhs) {
            return lhs.cost() < rhs.cost();
        });
    }

    vector<int>& worker(vector<vector<int>>& workers) const {return workers[wi];}
    Bike& top() {return prefs[offset];}
    void inc() {offset++;}
    void dec() {offset--;}
    bool can_inc() {return (offset + 1) < prefs.size();}
}; 

class Solution {
public:

    int cost(vector<Worker>& workers) {int s = 0; for(auto&w:workers)s+=w.top().cost();return s;}

    int opt(vector<Worker>& workers) {
        vector<int> inced {};
        int cst = INT32_MAX;
        int c[10] = {};
        int mx_c = 0;
        int bi = 0;
        for (auto &w : workers) {
            if (mx_c < ++c[w.top().bi()]) {
                mx_c = c[w.top().bi()];
                bi = w.top().bi();
            }
        }
        if (mx_c == 1)
            return cost(workers);

        int cannot_inc = 0;
        int first_ci_i = -1;
        for (int i = 0; i < workers.size(); i++) {
            auto &w = workers[i];
            if (w.top().bi() == bi) {
                if (!w.can_inc()) {
                    cannot_inc++;
                    if (first_ci_i != -1) 
                        first_ci_i = i;
                }
                w.inc();
                inced.push_back(i);
            }
        }

        if (cannot_inc == 1) {
            workers[first_ci_i].dec();
            cst = opt(workers);
        } else if (cannot_inc) {
            cst = INT32_MAX;
        } else {
            int mn = INT32_MAX;
            for (auto i : inced) {
                auto& w = workers[i];
                w.dec();
                mn = std::min(opt(workers), mn);
                w.inc();
            }
            cst = mn;
        }
        for (int i : inced) {
            workers[i].dec();
        }
        return cst;
    }
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<Worker> ws {};
        for (int i = 0; i < workers.size(); i++) {
            ws.emplace_back(workers, bikes, i);
        }
        return opt(ws);
    }
};


// class Solution {
// public:

//     void swap(int perm[10], int i, int j) {
//         int t = perm[i];
//         perm[i] = perm[j];
//         perm[j] = t;
//     }

//     int man(vector<int>& worker, vector<int>& bike) {
//         return std::abs(worker[0] - bike[0])
//             + std::abs(worker[1] - bike[1]);
//     }

//     int cost(vector<vector<int>>& workers, vector<vector<int>>& bikes, int perm[10]) {
//         int s = 0;
//         for (int i = 0; i < workers.size(); i++) {
//             s += man(workers[i], bikes[perm[i]]);
//         }
//         return s;
//     }

//     int srch(vector<vector<int>>& workers, vector<vector<int>>& bikes, int perm[10], int k) {
//         if (k == 1)
//             return cost(workers, bikes, perm);

//         int mn = srch(workers, bikes, perm, k-1);
//         for (int i = 0; i < k - 1; i++) {
//             if (k&1) {
//                 swap(perm, 0, k-1);
//             } else {
//                 swap(perm, i, k-1);
//             }
//             mn = std::min(srch(workers, bikes, perm, k-1), mn);
//         }
//         return mn;
//     }

//     int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
//         int perm[10] = {0,1,2,3,4,5,6,7,8,9};
//         return srch(workers, bikes, perm, bikes.size());
//         // int mn = cost(workers, bikes, perm);
//         // int c[10] = {0};

//         // int i = 1;
//         // while (i < bikes.size()) {
//         //     if (c[i] < i) {
//         //         if (i & 1) {
//         //             swap(perm, c[i], i);
//         //         } else {
//         //             swap(perm, 0, i);
//         //         }

//         //         mn = std::min(cost(workers, bikes, perm), mn);
//         //         c[i] += 1;
//         //         i = 1;
//         //     } else {
//         //         c[i] = 0;
//         //         i++;
//         //     }
//         // }
//         // return mn;
//     }
// };