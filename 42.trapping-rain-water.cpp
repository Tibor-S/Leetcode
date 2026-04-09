#include <algorithm>
#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
const int L = 0, R = 1;
class Solution {
public:
    int trap(vector<int>& height) {
        int i[2] = {0, (int)height.size()-1};
        int mx[2] = {height[i[L]], height[i[R]]};
        int sum = 0;
        
        while (i[L] < i[R]) {
            if (mx[L] <= mx[R]) {
                i[L]++;
                mx[L] = std::max(height[i[L]], mx[L]);
                sum += mx[L] - height[i[L]];
            } else {
                i[R]--;
                mx[R] = std::max(height[i[R]], mx[R]);
                sum += mx[R] - height[i[R]];
            }
        }

        return sum;
    }
};
// @lc code=end

