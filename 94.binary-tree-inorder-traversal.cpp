#include "treenode.h"
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

// @lc code=start
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret {};
        aux(root, ret);
        return ret;
    }
    void aux(TreeNode* root, vector<int> &ret) {
        if (!root)
            return;

        aux(root->left, ret);
        ret.push_back(root->val);
        aux(root->right, ret);
    }
};
// @lc code=end

