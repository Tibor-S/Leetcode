#include <string>
using std::string;

/*
 * @lc app=leetcode id=3227 lang=cpp
 *
 * [3227] Vowels Game in a String
 */


/*
Winner:
tot Al  Bob
0   B   B
1   A   A
2   A   B
3   A   A
4   A   B
5
*/

// @lc code=start
class Solution {
public:
    bool doesAliceWin(string s) {
        for (char c: s) {
            switch (c) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

