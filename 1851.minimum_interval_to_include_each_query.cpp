#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////]

bool contains(const std::vector<int>&interval, int val) { return val >= interval[0] && val <= interval[1]; }
// bool contains_cmp(const std::vector<int>&interval, int val) {
//     return contains(interval, val) && interval[0] <= val;
// }
int len(const std::vector<int>&interval) { return interval[1] - interval[0] + 1; }
bool length_comp(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    return len(lhs) < len(rhs);
}
// struct ContainsComp {
//     int val;
//     ContainsComp(int val) : val(val) {}
//     bool contains_comp(const std::vector<int>& lhs, const std::vector<int>& rhs) {
//         return !contains(lhs, val) || contains(rhs, val);
//     }
// };
struct Comp {
    bool operator()(const std::vector<int>&lhs, const std::vector<int>&rhs) {
        int llhs = len(lhs);
        int lrhs = len(rhs);
        if (llhs == lrhs) return lhs[1] < rhs[1];
        return llhs < lrhs;
    }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        std::sort(intervals.begin(), intervals.end(), Comp());
        std::vector lengths {intervals.begin()};
        while (lengths.back() != intervals.end()) {
            lengths.push_back(std::upper_bound(lengths.back(), intervals.end(), *lengths.back(), length_comp));
        }
        for (int qi = 0; qi < queries.size(); qi++) {
            int q = queries[qi];
            bool found = false;
            for (int li = 0; li < lengths.size() - 1; li++) {
                auto first = lengths[li];
                auto last = lengths[li+1];
                while (first != last) {
                    auto it = first;
                    auto dist = std::distance(first, last);
                    std::advance(it, dist / 2);
                    if (contains(*it, q)) { queries[qi] = len(*it); found = true; break;}
                    if ((*it)[0] < q) first = it + 1;
                    if ((*it)[0] > q) last = it;
                }
                if (found) break;
            }
            if (!found) queries[qi] = -1;
        }
        return queries;
    }
};