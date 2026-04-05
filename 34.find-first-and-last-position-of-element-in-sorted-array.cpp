#include <algorithm>
#include <iterator>
#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lb = std::lower_bound(nums.begin(), nums.end(), target);
        auto ub = std::upper_bound(nums.begin(), nums.end(), target);
        
        if (lb == ub) {
            return {-1, -1};
        } else {
            return {
                (int) std::distance(nums.begin(), lb),
                (int) std::distance(nums.begin(), ub) - 1
            };
        }
    }
};
// @lc code=end

