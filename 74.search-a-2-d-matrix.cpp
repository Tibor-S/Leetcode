#include <algorithm>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto row = std::upper_bound(
            matrix.begin(), 
            matrix.end(),
            target,
            [](auto val, auto &it) {
                return val < it[0];
            }
        );

        if (row == matrix.begin()) return false;
        row--;

        auto el = std::lower_bound(
            row->begin(),
            row->end(),
            target
        );
        if (el == row->end()) return false;
        return *el == target;
    }
};
// @lc code=end

