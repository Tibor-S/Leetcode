#include <string>
using std::string;
/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int val(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }

    int romanToInt(string s) {
        int tot = 0;
        int i = 0; 
        for (; i < s.length() - 1; i++) {
            int curr = val(s[i]);
            int next = val(s[i+1]);
            
            if (curr < next) {
                curr = next - curr;
                i++;
            } 

            tot += curr;
        }
        if (i < s.length())
            tot += val(s[i]);

        return tot;
    }
};
// @lc code=end

