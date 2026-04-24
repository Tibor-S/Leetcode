#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(1<<n);
        for (int b = 0; b < n; b++) {
            for (int i = 0; i < (1 << b); i++)
                ret[(1<<(b+1))-i-1] = ret[i] | (1<<b);
        }
        return ret;
    }
};
// @lc code=end

