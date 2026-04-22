#include <algorithm>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto begin = std::lower_bound(
            intervals.begin(), 
            intervals.end(), 
            newInterval[0],
            [](auto &it, int val) {
                return it[1] < val;
            }
        );
        auto end = std::upper_bound(
            begin, 
            intervals.end(), 
            newInterval[1],
            [](int val, auto &it) {
                return val < it[0];
            }
        );

        if (begin == end) {
            intervals.insert(begin, newInterval);
            return intervals;
        }

        begin->at(0) = std::min(begin->at(0), newInterval[0]);
        begin->at(1) = std::max((end - 1)->at(1), newInterval[1]);

        intervals.erase(begin+1, end);

        return intervals;
    }
};
// @lc code=end

