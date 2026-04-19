#include <algorithm>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs = nums[0];
        int bs = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cs = std::max(nums[i], cs + nums[i]);
            bs = std::max(cs, bs);
        }

        return bs;
    }
};
// @lc code=end

