#include <map>
#include <string>
#include <vector>
using std::vector;
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
    std::map<int, vector<int>> cols;
    vector<vector<int>>ret;
    struct indexed {
        TreeNode*node;
        int col;
    };

    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        vector<indexed> nodes = {{root, 0}};
        for (int i = 0; i < nodes.size(); i++) {
            auto &ind = nodes[i];
            auto node = ind.node;
            auto col =  ind.col;

            cols[col].push_back(node->val);
            if (node->left) nodes.push_back({node->left, col-1});
            if (node->right) nodes.push_back({node->right, col+1});
        }
        for (auto& [col, vec] : cols) ret.push_back(vec);

        return ret;
    }
};