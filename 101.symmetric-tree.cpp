#include "treenode.h"
/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if ((root->left != nullptr) ^ (root->right != nullptr)) return false;
        return !root->left || aux(root->left, root->right);
    }
    
    bool aux(TreeNode *lft, TreeNode *rgt) {
        if (lft->val != rgt->val) return false;
        if ((lft->left != nullptr) ^ (rgt->right != nullptr)) return false;
        if ((lft->right != nullptr) ^ (rgt->left != nullptr)) return false;
        if (lft->left && !aux(lft->left, rgt->right)) return false;
        if (lft->right && !aux(lft->right, rgt->left)) return false;
        return true;
    }
};
// @lc code=end

