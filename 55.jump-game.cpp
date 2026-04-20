#include <algorithm>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#define D(i) nums[i]
#define CAN_JUMP(i) (nums[i] == -1)
#define CANNOT_JUMP(i) (nums[i] == -2)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return canJump(0, nums);
    }
    bool canJump(int begin, vector<int>& nums) {
        if (CAN_JUMP(begin) || begin == nums.size() - 1)
            return true;

        if (CANNOT_JUMP(begin)) {
            return false;
        }
        for (
            int i = std::min(begin+D(begin),(int) nums.size()-1);
            i > begin;
            i--
        ) {
            if (canJump(i, nums)) {
                nums[i] = -1;
                return true;
            }
            nums[i] = -2;
        }

        return false;
    }
};
// @lc code=end

