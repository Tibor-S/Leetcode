#include "treenode.h"
#include <algorithm>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ret {};
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        aux(root, 0);
        std::reverse(ret.begin(), ret.end());
        return ret;
    }

    void aux(TreeNode* root, int level) {
        if (!root)
            return;
        if (ret.size() == level)
            ret.emplace_back();

        aux(root->left, level + 1);
        aux(root->right, level + 1);
        ret[level].push_back(root->val);
    }
};
// @lc code=end

