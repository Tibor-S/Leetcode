#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int place = nums1.size() - 1;
        int i1 = m-1, i2 = n-1;
        while (i1 >= 0 && i2 >= 0) {
            if (nums1[i1] > nums2[i2]) {
                nums1[place--] = nums1[i1--];
            } else {
                nums1[place--] = nums2[i2--];
            }
        }

        while (i2 >= 0) {
            nums1[place--] = nums2[i2--];
        }
    }
};
// @lc code=end

