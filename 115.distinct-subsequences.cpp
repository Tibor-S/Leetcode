#include <cstdint>
#include <string>
using std::string;

/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

/*


r   a   b   b   b   i   t   [solutions]
r   a   b   b   i   t       0
r   a   b   b   i       t   0
r   a   b   b       i   t   1
r   a   b       b   i   t   2
r   a       b   b   i   t   3


b   a   b   g   b   a   g   
b   a   g                   
b   a       g               
b   a                   g
b                   a   g 
        b           a   g
                b   a   g


b   a   b   g   b   a   g
1       1       1
    1               3
            1           4

what if check is bbag (3)

b   a   b   g   b   a   g
1       1       1
0       1       2
    0               3

what if check is babg

b   a   b   a   g   b   a   g
1       1           1
    1       2           3
0       1           3   
                1           4

what if check is ababg

a   b   a   b   a   g   b   a   g
1       1       1           1
    1       2           3   
        1       3           6
    0       1           4
                    1           5

*/


// @lc code=start
class Solution {
    uint64_t count[1000] = {};

public:
    int numDistinct(string t, string s) {
        uint64_t sum = 0;

        char sc = s[0];
        for (int i = 0; i < t.length(); i++) {
            char tc = t[i];
            if (sc == tc)
                count[i] = 1;
        }

        for (int si = 1; si < s.length(); si++) {
            char sc = s[si];
            sum = 0;
            for (int i = 0; i < t.length(); i++) {
                char tc = t[i];
                uint64_t saveme;
                if (sc == tc)
                    saveme = sum;
                else
                    saveme = 0;
                sum += count[i];
                count[i] = saveme;
            }
        }

        sum = 0;
        for (int i = 0; i < t.length(); i++) {
            sum += count[i];
        }

        return sum;
    }

};
// @lc code=end
