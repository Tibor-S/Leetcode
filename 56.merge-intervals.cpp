#include <algorithm>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(
            intervals.begin(), 
            intervals.end(), 
            [](vector<int> &l, vector<int> &r){
                if (l[0] == r[0])
                    return l[1] < r[1];
                return l[0] < r[0];
            }
        );

        vector<vector<int>> ret {};

        for (int i = 0; i < intervals.size();) {
            auto& interval = intervals[i];
            i++;
            for (; i < intervals.size(); i++) {
                auto& new_interval = intervals[i];
                if (new_interval[0] <= interval[1]) {
                    interval[1] = std::max(new_interval[1], interval[1]);
                } else {
                    break;
                }
            }
            ret.push_back(interval);
        }

        return ret;
    }
};
// @lc code=end

