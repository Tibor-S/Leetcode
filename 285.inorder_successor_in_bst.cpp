#include <string>
using std::string;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:

    TreeNode* furthest_left(TreeNode *node) {
        if (!node->left) return node;
        return furthest_left(node->left);
    }

    TreeNode* find_parent(TreeNode *node, TreeNode *p, TreeNode* smallest) {
        if (p->val > node->val) {
            if (node->right == p) return smallest;
            return find_parent(node->right, p, smallest);
        } else {
            if (node->left == p) return node;
            return find_parent(node->left, p, node);
        }
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right) return furthest_left(p->right);
        if (root == p) return nullptr;

        return find_parent(root, p, nullptr);
    }
};