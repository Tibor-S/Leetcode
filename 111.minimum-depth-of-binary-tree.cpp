#include "treenode.h"
#include <algorithm>
/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 */

// @lc code=start
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return 1 + std::min(
            left ? left : right,
            right ? right : left
        );
    }
};
// @lc code=end

