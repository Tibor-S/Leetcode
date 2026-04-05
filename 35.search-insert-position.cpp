#include <algorithm>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return std::distance(nums.begin(), std::lower_bound(nums.begin(), nums.end(), target));
    }
};
// @lc code=end

