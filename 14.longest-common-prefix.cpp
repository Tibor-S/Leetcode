#include <string>
#include <vector>
using std::string;
using std::vector;

/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            for (int j = 0; j < ret.size(); j++) {
                if (ret[j] != strs[i][j]) {
                    ret.resize(j);
                }
            }
        }
        return ret;
    }
};
// @lc code=end

