#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */


// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums.size()) {
                nums[i] = nums.size() + 1;
            } else if (nums[i] < 1) {
                nums[i] = nums.size() + 1;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            int expected = i+1;
            while (nums[i] != expected && nums[i] <= nums.size()) {
                int j = nums[i] - 1;

                // nums[j] already holds correct
                if (nums[j] == j + 1) {
                    nums[i] = nums.size() + 1;
                    break;
                }
                
                // swap
                nums[i] = nums[j];
                nums[j] = j + 1;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums.size()) {
                return i + 1;
            }
        }

        return nums.size() + 1;
    }
};
// @lc code=end

