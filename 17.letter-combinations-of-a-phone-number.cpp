#include <string>
#include <unordered_map>
#include <vector>
using std::vector;
using std::string;
using std::unordered_map;

/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    unordered_map<char, vector<char>> possible {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };

    void append_digit(char digit, vector<string>& dst) {
        auto&pos = possible[digit];
        for (string&ds:dst) {
            ds.append(1, pos[0]);
        }
        int ci = dst[0].length()-1;
        int len = dst.size();
        for (int i = 1; i < pos.size(); i++) {
            char appendage = pos[i];
            for (int si = 0; si < len; si++) {
                string ns = dst[si];
                ns[ci] = appendage;
                dst.push_back(ns);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ret {}; 
        for (char app:possible[digits[0]]) {
            ret.push_back(string(1,app));
        }  
        for (int i = 1; i < digits.length(); i++) {
            append_digit(digits[i], ret);
        }
        return ret;
    }
};
// @lc code=end

