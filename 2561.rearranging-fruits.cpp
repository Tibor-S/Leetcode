#include <algorithm>
#include <cstdint>
#include <deque>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////



/*

1   4   6   6   7   8
2   2   5   5   5   9

can exchange 1:
1:  2   5   9
4:  5   9
6:  9
7:  9
8:  9
can exchange 2:
2:  4   6   7   8
5:  6   7   8
9:


*/

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        long long  mn = INT32_MAX;
        std::unordered_set<int> p {};
        std::map<int, int> count[2] {};

        for (int n : basket1) {count[0][n]++; p.insert(n); mn = std::min(n, (int)mn);}
        for (int n : basket2) {count[1][n]++; p.insert(n); mn = std::min(n, (int)mn);}

        for (int n : p) {
            int c[2] {count[0][n], count[1][n]};

            if (c[0] == c[1]) {
                count[0].erase(n);
                count[1].erase(n);
            } else if (c[0] > c[1]) {
                if ((c[0] + c[1]) % 2) return -1;
                count[0][n] = (c[0] - c[1]) / 2;
                count[1].erase(n);
            } else {
                if ((c[0] + c[1]) % 2) return -1;
                count[1][n] = (c[1] - c[0]) / 2;
                count[0].erase(n);
            }
        }

        std::deque<int> dq[2] {};
        for (int i = 0; i < 2; i++)
            for (auto &[n, c] : count[i])
                for (int j = 0; j < c; j++)
                    dq[i].push_back(n);

        if (dq[0].size() != dq[1].size()) return -1;

        long long  mnnnn = mn * (dq[0].size() + dq[1].size());
        long long  ret = 0;
        while (!dq[0].empty()) {
            long long  dqmn[2] = {dq[0].front(), dq[1].front()};
            long long  dqmx[2] = {dq[0].back(), dq[1].back()}; 
            if (dqmn[0] <= dqmn[1]) {
                ret += dqmn[0];
                dq[0].pop_front();
                dq[1].pop_back();
            } else {
                ret += dqmn[1];
                dq[0].pop_back();
                dq[1].pop_front();
            }
            mnnnn = std::min(ret + mn * (long long) (dq[0].size() + dq[1].size()), mnnnn);
        }
        return mnnnn;
    }
};