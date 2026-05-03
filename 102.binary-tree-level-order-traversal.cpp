#include "treenode.h"
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ret {};
        if (root) aux(root, 0, ret);
        return ret;
    }

    void aux(TreeNode *root, int level, vector<vector<int>> &ret) {
        if (ret.size() == level) ret.emplace_back();
        ret[level++].push_back(root->val);
        if (root->left) aux(root->left, level, ret);
        if (root->right) aux(root->right, level, ret);
    }
};
// @lc code=end

