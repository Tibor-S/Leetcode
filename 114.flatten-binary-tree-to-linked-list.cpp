#include "treenode.h"
#include <utility>
/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 */

// @lc code=start
class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) return;
        flattened_end(root);
    }
    
    TreeNode *flattened_end(TreeNode *root) {
        if (root->left && root->right) {
            auto left_end = flattened_end(root->left);
            auto end = flattened_end(root->right);
            left_end->right = root->right;
            root->right = root->left;
            root->left = nullptr;
            return end;
        } else if (root->left) {
            auto end = flattened_end(root->left);
            std::swap(root->left, root->right);
            return end;
        } else if (root->right) {
            return flattened_end(root->right);
        } else {
            return root;
        }
    }
};
// @lc code=end

