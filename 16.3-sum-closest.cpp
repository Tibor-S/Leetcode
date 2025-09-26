#include <cstdint>
#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

/*

x + y + z = target + d, minimize |d|;
x + y + z = target
(x - target) + (y - target) + (z - target) = - 2*target + d
-dx - dy - dz = -2target + d
*/

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mnd = INT32_MAX;
        int mnx = 0;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i+1; j < nums.size(); j++)
                for (int k = j+1; k < nums.size(); k++)
                    if (std::abs(target - (nums[i] + nums[j] + nums[k])) < mnd) {
                        mnd = std::abs(target - (nums[i] + nums[j] + nums[k]));
                        mnx = nums[i] + nums[j] + nums[k];
                    }
                
        return mnx;
    }
};
// @lc code=end

