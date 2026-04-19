#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
#define JUMP_COUNT(i) nums[i] - 1001
#define SET_JUMP_COUNT(i, jc) nums[i] = 1001 + jc
class Solution {
public:
    int jump(vector<int>& nums) {
        SET_JUMP_COUNT(nums.size()-1, 0);
        for (int i = nums.size()-2; i >= 0; i--) {
            if (i+nums[i] >= nums.size()-1)
                SET_JUMP_COUNT(i, 1);
            else {
                int mn = JUMP_COUNT(i+1);
                for (int j = i+2; j <= i+nums[i]; j++) {
                    mn = std::min(JUMP_COUNT(j), mn);
                }
                SET_JUMP_COUNT(i, mn+1);
            }
        }
        return JUMP_COUNT(0);
    }
};
// @lc code=end

