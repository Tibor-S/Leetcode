#include <string>
using std::string;
/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        auto it = s.end();
        while (s.begin() != it--) {
            if (*it != ' '){
                break; 
            }       
        }
        it++;

        auto end = it;
        while (s.begin() != it--) {
            if (*it == ' '){
                break; 
            }
        }
        it++;

        return end - it; 
    }
};
// @lc code=end

