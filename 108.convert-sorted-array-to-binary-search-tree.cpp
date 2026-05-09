#include "treenode.h"
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return aux(0, nums.size(), nums);
    }
    TreeNode *aux(int s, int e, vector<int> &nums) {
        if (e - s == 0) return nullptr;
        if (e - s == 1) return new TreeNode(nums[s]);

        int m = (e + s) / 2;
        TreeNode *head = new TreeNode(nums[m]);
        head->left = aux(s, m, nums);
        head->right = aux(m+1, e, nums);

        return head;
    }
};
// @lc code=end

