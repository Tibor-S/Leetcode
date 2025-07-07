#include <string>
using std::string;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    struct bst {
        int lb; // high if search left, low if search right
        int hb; // high if search left, low if search right
        int size;
        bool keep_going;
    };

    bst search(TreeNode* node) {
        if (node->left && node->right) {
            auto left = search(node->left);
            auto right = search(node->right);
            auto &largest = left.size > right.size ? left : right;
            if (!left.keep_going || !right.keep_going) {
                largest.keep_going = false;
                return largest;
            }

            if (left.hb >= node->val) {
                largest.keep_going = false;
                return largest;
            }

            if (right.lb <= node->val) {
                largest.keep_going = false;
                return largest;
            }

            return {.lb = left.lb, .hb = right.hb, .size = left.size + right.size + 1, .keep_going = true};

        } else if (node->left) {
            auto left = search(node->left);
            if (!left.keep_going) return left;

            if (left.hb >= node->val) {
                left.keep_going = false;
                return left;
            }

            left.hb = node->val;
            left.size++;
            return left;

        } else if (node->right) {
            auto right = search(node->right);
            if (!right.keep_going) return right;

            if (right.lb <= node->val) {
                right.keep_going = false;
                return right;
            }

            right.lb = node->val;
            right.size++;
            return right;
        }

        return bst {.lb = node->val, .hb = node->val, .size = 1, .keep_going = true};
    }

    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        return search(root).size;
    }
};