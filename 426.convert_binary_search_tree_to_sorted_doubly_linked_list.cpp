#include <string>
using std::string;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:

    Node* circ(Node* node) {
        if (node->left && node->right) {
            Node* lmin = circ(node->left);
            Node* rmin = circ(node->right);
            Node* lmax = lmin->left;
            Node* rmax = rmin->left;
            lmax->right = node;
            node->left = lmax;
            rmin->left = node;
            node->right = rmin;
            lmin->left = rmax;
            rmax->right = lmin; 
            return lmin;
        } else if (node->left) {
            Node* min = circ(node->left);
            Node* max = min->left;
            max->right = node;
            node->left = max;
            min->left = node;
            node->right = min;
            return min;
        } else if (node->right) {
            Node* min = circ(node->right);
            Node* max = min->left;
            max->right = node;
            node->left = max;
            min->left = node;
            node->right = min;
            return node;
        }
        node->left = node->right = node; 
        return node;
    }

    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        return circ(root);
    }
};