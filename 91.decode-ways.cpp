#include <string>
using std::string;
/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
const bool _SINGLE[10] = {
    false, true, true, true, true, 
    true, true, true, true, true
};
const bool _DOUBLE[10][10] = {
    {false},
    {
        true,true,true,true,true,
        true,true,true,true,true,
    },
    {
        true,true,true,true,true,
        true,true,
    }
};
#define N(c) ((c) - '0')
#define SINGLE(c) (_SINGLE[N(c)])
#define DOUBLE(cf,cl) (_DOUBLE[N(cf)][N(cl)])
class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 1) {
            return SINGLE(s[0]);
        }
        int paths[100] {};
        int i = s.length()-1;
        bool must_single = false;
        bool must_double = false;
        if (SINGLE(s[i]) && DOUBLE(s[i-1], s[i])) {
            paths[i--] = 1;
            paths[i--] = 2;
        } else if (SINGLE(s[i])) {
            paths[i--] = 1;
        } else if (DOUBLE(s[--i], s[i+1])) {
            paths[i--] = 1;
            must_single = true;
        } else {
            return 0;
        }

        for(; i>=0; i--) {
            if (must_double) {
                if (DOUBLE(s[i], s[i+1])) {
                    paths[i] = paths[i+2];
                    must_single = true;
                    must_double = false;
                    continue;
                } else {
                    return 0;
                }
            }

            if (SINGLE(s[i])) {
                if (must_single) {
                    paths[i] = paths[i+1];
                } else if (DOUBLE(s[i], s[i+1])) {
                    paths[i] = paths[i+1] + paths[i+2];
                }  else {
                    paths[i] = paths[i+1];
                }
                must_single = false;
                must_double = false;
            } else {
                must_single = false;
                must_double = true;
            }
        }
        return paths[0];
    }
};
// @lc code=end

