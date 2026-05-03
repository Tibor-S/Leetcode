#include "treenode.h"
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ret {};
        if (root) aux(root, 0, ret);
        return ret;
    }

    void aux(TreeNode *root, int level, vector<vector<int>> &ret) {
        if (ret.size() == level) ret.emplace_back();
        if (level&1) ret[level].insert(ret[level++].begin(), root->val);
        else ret[level++].push_back(root->val);
        if (root->left) aux(root->left, level, ret);
        if (root->right) aux(root->right, level, ret);
    }
};
// @lc code=end

