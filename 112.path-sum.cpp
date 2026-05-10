#include "treenode.h"
/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */

// @lc code=start
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        if (!root->left && !root->right)
            return root->val == targetSum;

        return hasPathSum(root->left, targetSum - root->val)
            || hasPathSum(root->right, targetSum - root->val);
    }
};
// @lc code=end

