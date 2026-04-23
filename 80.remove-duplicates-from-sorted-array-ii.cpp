#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int move_back = 0;
        
        int prev = nums[1];
        int count = 1 + (nums[0] == nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            int curr = nums[i];
            if (prev == curr) {
                if (count++ == 1) {
                    nums[i - move_back] = curr;
                } else {
                    move_back++;
                }
            } else {
                prev = curr;
                count = 1;
                nums[i - move_back] = curr;
            }
        }
        return nums.size() - move_back;
    }
};
// @lc code=end

