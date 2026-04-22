#include <string>
using std::string;
/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
#define GET(s) ((s)[(s).length() - i - 1])
#define SET(s, v) (s)[(s).length() - i - 1] = v
#define ONE(s) (GET(s) == '1')
class Solution {
public:
    string addBinary(string a, string b) {
        string *res;
        string *tt;
        if (a.length() >= b.length()) {res = &a; tt = &b;}
        else {res = &b; tt = &a;}        

        bool carry = false;
        int i = 0;
        for (; i < tt->length(); i++) {
            bool r = ONE(*res), t = ONE(*tt);
            if (r ^ t ^ carry)
                SET(*res, '1');
            else SET(*res, '0');
            bool sh = r && t;
            carry = r && t || carry && r || carry && t;
        }

        for (; i < res->length() && carry; i++) {
            bool r = ONE(*res);
            if (r) 
                SET(*res, '0');
            else {
                SET(*res, '1');
                carry = false;
                break;
            }
        }

        if (carry) {
            res->insert(res->begin(), '1');
        }

        return *res;
    }
};
// @lc code=end

