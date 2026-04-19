#include <bitset>
#include <string>
using std::string;
using std::bitset;
/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        bitset<9> locked_dec {};
        bitset<9> locked_mid {};
        bitset<9> locked_inc {};
        return place(n, locked_dec, locked_mid, locked_inc);
    }

    static int place(
        int n, 
        bitset<9> locked_dec, 
        bitset<9> locked_mid, 
        bitset<9> locked_inc
    ) {
        if (locked_mid.to_ullong() == (1 << n) - 1) {
            return 1;
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (locked_dec[i] || locked_mid[i] || locked_inc[i])
                continue;

            bitset<9> new_locked_dec = locked_dec >> 1;
            if (i > 0) new_locked_dec[i-1] = true;
            bitset<9> new_locked_inc = locked_inc << 1;
            if (i < n-1) new_locked_inc[i+1] = true;
            locked_mid[i] = true;
            ret += place(
                n,
                new_locked_dec,
                locked_mid,
                new_locked_inc
            );
            locked_mid[i] = false;
        }

        return ret;
    }
};
// @lc code=end

