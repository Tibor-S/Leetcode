#include <string>
using std::string;

/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

/*

captures:
p\s a   a   b
c*  
a*  x   x
b           x

traversal:
(1) If cap and last return true;
(5) If cap and last(sc) => return last_check;
(2) If no cap and repeating pi++;
(3) If cap and repeating {si++; si++, pi++};
(5) If cap si++, pi++;

captures:
p\s a
a   1
b*      
*/

// @lc code=start
class Solution {
public:

    bool checked[20][20] = {}; // mem[si][pi]

    bool is_repeating(string &p, int pi) {
        if (pi+1 < p.length()) {
            return p[pi+1] == '*';
        } 
        return false;
    }

    bool captures(char sc, char pc) {
        return pc == '.' || pc == sc;
    }
    
    bool last_check(string &p, int npi) {
        if ((p.length() - npi) & 1) return false;
        for (int i = npi; i < p.length() - 1; i+=2) {
            if (p[i+1] != '*') return false;
        }
        return true;
    }

    bool match(string &s, string &p, int si, int pi) {
        if (si == s.length() || pi == p.length()) return false;
        if (checked[si][pi]) return false;
        checked[si][pi] = true;
        char sc = s[si], pc = p[pi];
        bool capture = captures(sc, pc);
        bool repeating = is_repeating(p, pi);
        int nsi = si+1, npi = repeating ? pi+2 : pi+1;
        // Last index check
        if (nsi == s.length() && npi == p.length())
            return capture;
        if (nsi == s.length() && capture)
            return last_check(p, npi) || (repeating && match(s, p, si, npi));
        if (repeating) {
            if (capture) 
                return match(s, p, nsi, pi) || match(s, p, nsi, npi) || match(s, p, si, npi);
            else
                return match(s, p, si, npi);
        } 
        return capture && match(s, p, nsi, npi);
    }

    bool isMatch(string s, string p) {
        return match(s, p, 0, 0);
    }
};
// @lc code=end

