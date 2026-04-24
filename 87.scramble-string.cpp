#include <array>
#include <cstdint>
#include <string>
using std::string;
/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
#define I(c) (((int) (c)) - ((int) 'a'))
const int CLEN = I('z') + 1;

using count_t = std::array<uint8_t, CLEN>;
using prefix_t = std::array<count_t, 31>;

void operator +=(count_t& a, count_t& b) {
    for (int i = 0; i < CLEN; i++) a[i] += b[i];
}
count_t operator -(count_t& a, count_t& b) {
    count_t res {};
    for (int i = 0; i < CLEN; i++) res[i] = a[i] - b[i];
    return res;
}
bool operator ==(count_t&a, int b) {
    for (int i = 0; i < CLEN; i++) b -= a[i];
    return b == 0;
}

class Solution {
public:
    prefix_t p1 {}, p2 {};
    char mem[30][30][31] {};
    
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) 
            return false;
        int len = s1.length();
        for (int i = 0; i < len; i++) {
            p1[i+1] += p1[i];
            p2[i+1] += p2[i];
            p1[i+1][I(s1[i])]++;
            p2[i+1][I(s2[i])]++;
        }

        if (p1[len] != p2[len])
            return false;

        return aux(0, 0, len);
    }

    bool aux(int st1, int st2, int len) {
        if (mem[st1][st2][len])
            return mem[st1][st2][len] == 1;
        if ((p1[st1+len] - p1[st1]) != (p2[st2+len] - p2[st2])) {
            mem[st1][st2][len] = -1;
            return false;
        }
        if (len == 1) {
            mem[st1][st2][len] = 1;
            return true;
        }

        for (int slen = 1; slen < len; slen++) {
            if (
                aux(st1, st2, slen)
                && aux(st1 + slen, st2 + slen, len - slen)
            ) {
                mem[st1][st2][len] = 1;
                return true;
            }

            if (
                aux(st1, st2+len-slen, slen)
                && aux(st1 + slen, st2, len - slen)
            ) {
                mem[st1][st2][len] = 1;
                return true;
            }
        }
        mem[st1][st2][len] = -1;
        return false;
    }
};
// @lc code=end

