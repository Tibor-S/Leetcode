#include <string>
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

a   =>  b
F   T   F
F   T   T
T   F   F
T   T   T

a\b 0   1
0   T   T
1   F   T

a' + b

s[i] == s[i+1] => s[i] != s[i+2]

*/

class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3) return s;
        string ret(s.begin(), s.begin() + 2);
        char p_2 = s[0];
        char p_1 = s[1];
        for (int i = 2; i < s.length(); i++) {
            char c = s[i];
            if (c != p_1 || c != p_2) {
                ret += c;
                p_2 = p_1;
                p_1 = c;
            }
        }
        return ret;
    }
};