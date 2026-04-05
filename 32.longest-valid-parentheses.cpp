#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using std::string;
using std::vector;

/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

/*

)   (   )   (   )   )
  x   o   x   o   x
      x   o   x

)   (   )   (   )   )
0   0   0   0   0   0
0   2       2       0
0   4               0   


)   (   
0   -1  0

(   (   )   )   (   )   (   (   )   (   (
0   0   0   0   0   0   0   0   0   0   0
0   2       0   2       0   2       -1   0
4                                       

(   (   )   )   (   )   (   (   )   (   (
  x   o   x   x   o   x   x   o   x   x
      o   x   x   x   x   x   x   x
          x   x

SUM:
4               6       0   2       

*/

// @lc code=start
struct range {
    int start;
    int end;
};

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) {
            return 0;
        }
        vector<range> valid = {};

        // Find singletons `()`

        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '(' && s[i+1] == ')') {
                valid.push_back(range {i, i+2});
                i++;
            }
        }

        // expand singletons
        bool change = true;
        while (change) {
            change = false;

            for (int i = 0; i < valid.size(); i++) {
                range &r = valid[i];
                int pre = r.start - 1;
                int suf = r.end;
                if (pre >= 0 && suf < s.length()) {
                    if (s[pre] == '(' && s[suf] == ')') {
                        change = true;
                        r.start = pre;
                        r.end = suf+1;
                    }
                }

                if (i+1 < valid.size()) {
                    if (r.end == valid[i+1].start) {
                        change = true;
                        r.end = valid[i+1].end;
                        valid.erase(valid.begin() + i+1);
                    }
                }
            }
        }

        // take max
        int mx = 0;
        for (range r : valid) {
            mx = std::max(r.end - r.start, mx);
        }

        return mx;
    }
};
// @lc code=end


const std::tuple<const char*, int> tests[] = {
    {"(()", 2},
    {")()())", 4},
    {"(())()(()((", 6},
    {"(()())", 6},
};

bool t(Solution& sol, const char* te, const int ex) {
    auto an = sol.longestValidParentheses(string(te));
    if (an != ex) {
        std::cout << "Failed test: " << std::endl;
        std::cout << "\tInput: " << te << std::endl;
        std::cout << "\tExpected: " << ex << std::endl;
        std::cout << "\tGot: " << an << std::endl;
        return false;
    }
    return true;
}

int main() {
    auto sol = Solution();
    for (int i = 0; i < 4; i++) {
        if (!t(
            sol, 
            std::get<0>(tests[i]), 
            std::get<1>(tests[i])
        )) return -1;
    }
    std::cout << "Passed all tests!" << std::endl;
}