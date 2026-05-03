#include "treenode.h"
/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */

// @lc code=start
bool operator==(TreeNode& p, TreeNode& q) {
    if (p.val != q.val) return false;
    if ((p.left != nullptr) ^ (q.left != nullptr)) return false;
    if ((p.right != nullptr) ^ (q.right != nullptr)) return false;
    return (!p.left || *p.left == *q.left) && (!p.right || *p.right == *q.right);
}
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p != nullptr) ^ (q != nullptr)) return false;
        if (!p) return true;
        return *p == *q;
    }
};
// @lc code=end

