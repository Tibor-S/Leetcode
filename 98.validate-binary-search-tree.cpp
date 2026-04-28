#include "treenode.h"
/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int dummy;
        return aux(root, &dummy, &dummy);
    }

    bool aux(TreeNode* root, int *min, int *max) {
        *min = root->val; *max = root->val;
        if (root->left) {
            int lmin, lmax;
            if (!aux(root->left, &lmin, &lmax))
                return false;
            if (lmax >= root->val)
                return false;

            *min = lmin;
        }
        if (root->right) {
            int rmin, rmax;
            if (!aux(root->right, &rmin, &rmax))
                return false;
            if (rmin <= root->val)
                return false;

            *max = rmax;
        }
        return true;
    }
};
// @lc code=end

