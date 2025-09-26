#include <cmath>
#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        vector<int> digits {};
        int i = 1, j = pow(10, log10(x));
        while (i < j) {
            if ((x / i) % 10 != (x / j) % 10) 
                return false;
            i *= 10;
            j /= 10;
        }

        return true;
    }
};
// @lc code=end

