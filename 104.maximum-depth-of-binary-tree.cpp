#include "treenode.h"
#include <algorithm>
/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */

// @lc code=start
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};
// @lc code=end

