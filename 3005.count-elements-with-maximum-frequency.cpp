#include <algorithm>
#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=3005 lang=cpp
 *
 * [3005] Count Elements With Maximum Frequency
 */

// @lc code=start
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int f = 1;
        int n = nums[0];
        int mxf = 0;
        int c = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == n) {
                f++;
            } else {
                if (f > mxf) {
                    mxf = f;
                    c = 1;
                } else if (f == mxf) {
                    c++;
                }
                f = 1;
                n = nums[i];
            }
        }
        if (f > mxf) {
            mxf = f;
            c = 1;
        } else if (f == mxf) {
            c++;
        }
        return c * mxf;
    }
};
// @lc code=end

