#include <unordered_set>
#include <vector>
using std::vector;
using std::unordered_set;
/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> exis {};
        auto it = nums.end();
        while (it-- != nums.begin()) {
            if (exis.contains(*it)) {
                nums.erase(it);
            } else {
                exis.insert(*it);
            }
        }
        return nums.size();
    }
};
// @lc code=end

