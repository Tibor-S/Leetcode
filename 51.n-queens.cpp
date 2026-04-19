#include <bitset>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::bitset;
/*
* @lc app=leetcode id=51 lang=cpp
*
* [51] N-Queens
*/

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret {};
        vector<string> curr {};
        bitset<9> locked_dec {};
        bitset<9> locked_mid {};
        bitset<9> locked_inc {};
        place(n, locked_dec, locked_mid, locked_inc, curr, ret);

        return ret;
    }

    static void place(
        int n, 
        bitset<9> locked_dec, 
        bitset<9> locked_mid, 
        bitset<9> locked_inc, 
        vector<string>& curr, 
        vector<vector<string>> &ret
    ) {
        if (curr.size() == n) {
            ret.emplace_back(curr);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (locked_dec[i] || locked_mid[i] || locked_inc[i])
                continue;

            bitset<9> new_locked_dec = locked_dec >> 1;
            if (i > 0) new_locked_dec[i-1] = true;
            bitset<9> new_locked_inc = locked_inc << 1;
            if (i < n-1) new_locked_inc[i+1] = true;
            locked_mid[i] = true;
            curr.push_back(placed(n, i));
            place(
                n,
                new_locked_dec,
                locked_mid,
                new_locked_inc,
                curr,
                ret
            );
            curr.pop_back();
            locked_mid[i] = false;
        }

    }

    static string placed(const int n, const int queen) {
        string base = string(n, '.');
        base[queen] = 'Q';
        return base;
    }
};
// @lc code=end

