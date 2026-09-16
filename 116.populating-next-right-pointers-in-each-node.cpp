#include "node.h"

/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
class Solution {
public:
    Node* branch[13];
    int level = 0;

    Node* connect(Node* root) {
        if (!root) 
            return root;

        level+=1;
        connect(root->right);
        connect(root->left);
        level-=1;
        root->next = branch[level];
        branch[level] = root;

        return root;
    }
};
// @lc code=end