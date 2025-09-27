#include <algorithm>
#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        std::sort(nums.begin(), nums.end());
        auto first = std::lower_bound(nums.begin(), nums.end(), val);        
        auto last = std::upper_bound(first, nums.end(), val);        
    
        nums.erase(first, last);
        return nums.size();
    }
};
// @lc code=end

