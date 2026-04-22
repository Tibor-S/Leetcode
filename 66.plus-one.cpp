#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() -1; i >= 0; i--) {
            if (++digits[i] == 10) {
                digits[i] = 0;
            } else {
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
// @lc code=end

