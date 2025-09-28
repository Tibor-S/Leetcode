#include <algorithm>
#include <functional>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 */

// @lc code=start
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        for (int i = 0; i < nums.size() - 2; i++) {
            int x = nums[i], y = nums[i+1], z = nums[i+2];
            if (x < y + z)
                return x + y + z;
        }

        return 0;
    }
};
// @lc code=end

