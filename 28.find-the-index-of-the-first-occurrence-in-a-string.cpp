#include <string>
using std::string;
/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = (int)haystack.length() - (int)needle.length() + 1;
        for (int i = 0; i < len; i++) {
            bool passed = true;
            for (int j = 0; j < needle.length(); j++) {
                if (haystack[i+j] != needle[j]) {
                    passed = false;
                    break;
                }
            }
            if (passed) 
                return i;
        }
        return -1;
    }
};
// @lc code=end

