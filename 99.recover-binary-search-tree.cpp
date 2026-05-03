#include "treenode.h"
#include <utility>
/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 */

// @lc code=start
class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *pats[2] = {nullptr, nullptr};
        previous(root, nullptr, pats);
        std::swap(pats[0]->val, pats[1]->val);
    }
    
    TreeNode* previous(TreeNode *node, TreeNode *gprev, TreeNode **pats) {
        if (node->left) {
            gprev = previous(node->left, gprev, pats);
        }

        if (gprev && gprev->val > node->val) {
            if (!pats[0]) pats[0] = gprev;
            pats[1] = node;
        }

        if (node->right) {
            return previous(node->right, node, pats);
        } else {
            return node;
        }
    }
};
// @lc code=end

