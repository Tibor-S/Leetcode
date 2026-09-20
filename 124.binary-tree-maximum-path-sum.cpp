#include "treenode.h"
#include <algorithm>
#include <cstdint>
/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

// @lc code=start
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int mx = INT32_MIN;
        aux(root, 0, &mx);
        return mx;
    }

    // returns sum of tree
    void aux(TreeNode* root, int parent_path, int* mx) {
        int partial;
        if (root->right) {
            partial = partial_path(root->right, mx);
        } else {
            partial = INT32_MIN;
        }

        int optimal_pass;
        if (parent_path < 0 && partial < 0) {
            optimal_pass = root->val;
        } else if (parent_path < 0) {
            optimal_pass = root->val + partial;
        } else if (partial < 0) {
            optimal_pass = root->val + parent_path;
        } else {
            *mx = std::max(root->val + parent_path + partial, *mx);
            optimal_pass = root->val + std::max(parent_path, partial);
        }   
        *mx = std::max(optimal_pass, *mx);

        if (root->left) {
            aux(root->left, optimal_pass, mx);
        }
    }

    // returns max path connecting to root
    int partial_path(TreeNode* root, int* mx) {
        int result;

        if (root->left && root->right) {
            int opt_l = partial_path(root->left, mx);
            int opt_r = partial_path(root->right, mx);
            if (opt_l < 0 && opt_r < 0) {
                result = root->val;
            } else if (opt_l < 0) {
                result = root->val + opt_r;
            } else if (opt_r < 0) {
                result = root->val + opt_l;
            } else {
                *mx = std::max(root->val + opt_l + opt_r, *mx);
                result = root->val + std::max(opt_l, opt_r);
            }
        } else if (root->left) {
            int opt_l = partial_path(root->left, mx);
            if (opt_l <= 0) {
                result = root->val;
            } else {
                result = root->val + opt_l;
            }
        } else if (root->right) {
            int opt_r = partial_path(root->right, mx);
            if (opt_r <= 0) {
                result = root->val;
            } else {
                result = root->val + opt_r;
            }
        } else {
            result = root->val;
        }
        *mx = std::max(result, *mx);

        return result;
    }
};
// @lc code=end

