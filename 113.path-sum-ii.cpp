#include "treenode.h"
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ret {};
    
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<int> history {};
        aux(root, targetSum, history);
        return ret;
    }

    void aux(TreeNode *root, int targetSum, vector<int> &history) {
        if (!root) return;

        history.push_back(root->val);

        if (!root->left && !root->right && root->val == targetSum)
            ret.emplace_back(history);

        aux(root->left, targetSum - root->val, history);
        aux(root->right, targetSum - root->val, history);

        history.pop_back();
    }
};
// @lc code=end

