#include <algorithm>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int pivot = nums[0];
        if (pivot == target) return true;
        auto begin = nums.begin();
        auto end = nums.end();
        while (++begin != end && *begin == pivot);
        while (end-- != begin && *end == pivot);
        end++;
        if (begin == end) return false;


        auto first = begin;
        auto last = end;
        while (first != last) {
            auto mid = first + (last - first) / 2;
            if (*mid >= pivot) {
                first = mid+1;
            } else {
                last = mid;
            }
        }

        if (target > pivot) {
            return std::binary_search(begin, first, target);
        } else {
            return std::binary_search(first, end, target);
        }
    }
};
// @lc code=end

