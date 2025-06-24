#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct SumNode {
    int val;
    int up_sum;
    SumNode* left = nullptr;
    SumNode* right = nullptr;
    int left_sum = 0;
    int right_sum = 0;
    SumNode(TreeNode* node) : val(node->val), up_sum(0) {
        if (node->left != nullptr) {
            left = new SumNode(node->left);
            left_sum = left->lower_sum();
        }
        if (node->right != nullptr) {
            right = new SumNode(node->right);
            right_sum = right->lower_sum();
        }
    }

    int lower_sum() {
        return val + left_sum + right_sum;
    }

    void set_up_sum(int sum) { 
        up_sum = sum; 
        if (left != nullptr) left->set_up_sum(up_sum + val + right_sum);
        if (right != nullptr) right->set_up_sum(up_sum + val + left_sum);
    }

    bool can_break(bool root = true) {
        if (!root && lower_sum() == up_sum) return true;
        if (left != nullptr) if (left->can_break(false)) return true;
        if (right != nullptr) if (right->can_break(false)) return true;
        return false;
    }
};

class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        auto sroot = new SumNode(root);
        sroot->set_up_sum(0);
        return sroot->can_break();
    }
};