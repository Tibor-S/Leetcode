#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdlib>
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
    vector<double> ds; // ascending in abs diff

    void search(TreeNode *node, double target) {
        double diff = target - node->val;
        auto it = std::upper_bound(ds.begin(), ds.end(), std::abs(diff), [](double val, double elem){
            return val < std::abs(elem);
        });
        ds.insert(it, diff);
        ds.pop_back();
        if (node->left) search(node->left, target);
        if (node->right) search(node->right, target);
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        ds = vector<double>(k, INFINITY);
        vector<int> ret(k);
        search(root, target);
        for (int i = 0; i < k; i++) {
            ret[i] = target - ds[i];
        }
        return ret;
    }
};