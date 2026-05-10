#include "treenode.h"

/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return height(root) != -1;
    }

    int height(TreeNode *root) {
        if (!root) return 0;

        int left_height = height(root->left);
        int right_height = height(root->right);
        if (left_height == -1 || right_height == -1) return -1;
        int diff = left_height - right_height;
        if (!diff || diff == 1) return left_height+1;
        if (diff == -1) return right_height+1;
        return -1;
    }
};
// @lc code=end

