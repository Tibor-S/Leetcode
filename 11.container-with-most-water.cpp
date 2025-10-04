#include <algorithm>
#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx = 0;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] == 0) continue;
            int di = mx / height[i];
            int org = i + std::max(1, di);
            for (int j = org; j < height.size(); j++) {
                mx = std::max(std::min(height[i], height[j]) * (j - i), mx);
            }
        }
        return mx;
    }
};
// @lc code=end
