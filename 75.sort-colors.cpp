#include <utility>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto place_0 = nums.begin();
        auto place_2 = nums.end()-1;
        auto it = nums.begin();
        while (it <= place_2) {
            if (*it == 0) {
                std::swap(*place_0, *it);
                place_0++;
                if (it < place_0) it = place_0;
            } else if (*it == 2) {
                std::swap(*it, *place_2);
                place_2--;
            } else {
                it++;
            }
        }
    }
};
// @lc code=end

