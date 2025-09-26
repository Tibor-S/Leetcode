#include <algorithm>
#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

// @lc code=start
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        std::sort(nums.begin(), nums.end());
        int c = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            for (int j = i+1; j < nums.size(); j++) {
                int t = nums[i] + nums[j];
                auto lb = std::lower_bound(nums.begin(), nums.end(), t);
                c += std::distance(nums.begin(), lb) - 2 - j + 1; 
            }
        }
        return c;
    }
};
// @lc code=end

