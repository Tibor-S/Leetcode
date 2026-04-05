#include <vector>
using std::vector;


/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // find end

        int begin = 0;
        int end = nums.size();
        int mid = (end + begin) >> 1;
        while (begin < mid) {
            if (nums[begin] < nums[mid]) {
                begin = mid;
            } else {
                end = mid;
            }
            mid = (end + begin) >> 1;
        }

        begin = 0;
        if (target < nums[0]) {
            begin = end;
            end = nums.size();
        }

        mid = (end + begin) >> 1;
        while (begin < mid) {
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                begin = mid;
            } else {
                end = mid;
            }
            mid = (end + begin) >> 1;
        }

        if (mid < nums.size() && nums[mid] == target) {
            return mid;
        }

        return -1;
    }
};
// @lc code=end

