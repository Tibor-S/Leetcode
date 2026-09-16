#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex+1);
        ret[0] = 1;
        ret[rowIndex] = 1;

        int n = rowIndex;
        for (int k = 1; k < (n+2)/2; k++) {
            int val = (static_cast<uint64_t>(ret[k-1]) * static_cast<uint64_t>(n-k+1))/k;
            ret[k] = val;
            ret[n-k] = val;
        }

        return ret;
    }
};
// @lc code=end

