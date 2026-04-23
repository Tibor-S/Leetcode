#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> curr {};
        place(1, n, k, curr, ret);
        return ret;
    }

    void place(int i, int n, int k, vector<int> &curr, vector<vector<int>> &ret) {
        if (i > n) return;
        place(i+1, n, k, curr, ret);
        curr.push_back(i);
        if (curr.size() == k) ret.emplace_back(curr);
        else place(i+1, n, k, curr, ret);
        curr.pop_back();
    }
};
// @lc code=end

