#include <string>
using std::string;

/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
    char alpha[256] = {};
public:
    bool isPalindrome(string s) {
        init();
        int li = 0;
        int ri = s.length() - 1;

        while (li < ri) {
            char lc = alpha[s[li]], rc = alpha[s[ri]];
            if (!lc) {
                li++;
                continue;
            } 
            if (!rc) {
                ri--;
                continue;
            } 
            
            if (lc != rc)
                return false;
            
            li++;
            ri--;
        }

        return true;
    }

    void init() {
        for (int c = 'a'; c <= 'z'; c++) {
            alpha[c] = c;
        }
        for (int c = 'A'; c <= 'Z'; c++) {
            alpha[c] = c - 'A' + 'a';
        }
        for (int c = '0'; c <= '9'; c++) {
            alpha[c] = c;
        }
    }
};
// @lc code=end

