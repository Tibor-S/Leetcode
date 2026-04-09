#include <algorithm>
#include <string>
using std::string;
/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

/*

num1: 43210
num2: ABCDE
rem: 
0      0       0       0       0
E0/10  0       0       0       0
E1/10  0       0       0       0

*   4           3           2           1           0
*   A           B           C           D           E
---------------------------------------------------------
*                                       (E1+R)%10   (E0)%10


num1.size(): 3
num2.size(): 5

r   i1  i2  rem
0   0   0   A1  0   0   0   0

1   1   0   A2  0   0   0   0
1   0   1   A2  B1  0   0   0

2   2   0   A3  0   0   0   0 
2   1   1   A3  B2
2   0   2   A3  B2  C1

3   2   1   
3   1   2
3   0   3

4   2   2
4   1   3
4   0   4

5   2   3
5   1   4

6   2   4



*/


// @lc code=start
#define GET(num, index) (num[num.size() - index - 1] - '0')
#define SET(num, index, val) (num[num.size() - index - 1] += val)
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string res = string(num1.size() + num2.size(), '0');
        char mul_rem[200];
        int sum = 0;
        int i1 = 0, i2 = 0;

        for (int r = 0; r < res.size(); r++) {
            i1 = std::min(r,(int)num1.size() - 1);
            i2 = r - i1; 
            if (i2 > 0) {
                sum += mul_rem[i2-1];
            }

            while (i1 >= 0 && i2 < num2.size()) {
                int n1 = GET(num1, i1);
                int n2 = GET(num2, i2);
                int prod = n1 * n2 + mul_rem[i2];
                sum += prod % 10;
                mul_rem[i2] = prod / 10;

                i1--;
                i2++;
            }

            SET(res, r, sum % 10);
            sum /= 10;
        }
        if (res[0] == '0') {
            return res.substr(1);
        } 
        return res;
    }
};
// @lc code=end

