#include <algorithm>
#include <array>
#include <stack>
#include <vector>
using std::vector;
using std::stack;
/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

/*

2   1   5   6   2   3   mx=6
1   1   5   2   2       mx=10
1   1   2   2           mx=6
1   1   2               mx=8
1   1                   mx=5
1                       mx=6

*/


// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int mx = 0;
        stack<std::array<int, 2>> hs {};
        for (int i = 0; i < heights.size(); i++) {
            int h = heights[i];
            int w = 1;
            while (!hs.empty()) {
                int prev = hs.top()[0];
                int prev_w = hs.top()[1];

                if (prev < h) {
                    hs.push({h, w});
                    break;
                } else if (prev == h) {
                    hs.top()[1] += w;
                    break;
                } else {
                    w += prev_w;
                    mx = std::max(prev * (w-1), mx);
                    hs.pop();
                }
            }

            if (hs.empty())
                hs.push({h, w});
        }

        int w = 0;
        while (!hs.empty()) {
            w += hs.top()[1];
            mx = std::max(hs.top()[0] * w, mx);
            hs.pop();
        }

        return mx;
    }
};
// @lc code=end

