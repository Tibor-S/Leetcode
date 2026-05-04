#include "treenode.h"
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */
/*

3   9   20  15  7
9   3   15  20  7
+   -   +   -

3   9   10  20  15  11  7
10  9   3   11  15  20  7
+   +   -   +   +   -



        3
    9           20
10          15      7
        11



3
9   20
10  x   15  7
x   x   11
*/
// @lc code=start
template<typename T>
struct pp {T pr, in;};
class Solution {
public:
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
        pp<int> i = {0, 0};
        pp<vector<int>&> order = {preorder, inorder};
        TreeNode *root = new TreeNode(preorder[i.pr++]);
        TreeNode *it = root;
        while (i.pr < preorder.size()) {
            it->left = head(&i, it->val, order);
            i.in++;
            if (i.pr < preorder.size())
                it->right = new TreeNode(preorder[i.pr++]);
            it = it->right;
        }
        return root;
    }

    TreeNode *head(pp<int> *i, int parent, pp<vector<int>&> order) {
        pp<int> val = {.pr = i->pr < order.pr.size() ? order.pr[i->pr] : -1, .in = order.in[i->in]};
        if (val.in == parent) {
            return nullptr;
        }

        TreeNode *node = new TreeNode(val.pr);
        i->pr++;

        node->left = head(i, node->val, order);
        i->in++;
        node->right = head(i, parent, order);

        return node;
    }
};
// @lc code=end

