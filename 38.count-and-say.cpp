#include <string>
using std::string;
/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string ret = "";
        string low = countAndSay(n - 1);
        char curr = low[0];
        int count = 1;
        for (int i = 1; i < low.length(); i++) {
            if (low[i] == curr) {
                count++;
            } else {
                ret.push_back('0' + count);
                ret.push_back(curr);
                curr= low[i];
                count = 1;
            }
        }
        ret.push_back('0' + count);
        ret.push_back(curr);
        return ret;
    }
};
// @lc code=end

