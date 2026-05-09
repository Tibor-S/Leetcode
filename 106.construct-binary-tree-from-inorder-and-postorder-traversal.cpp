#include "treenode.h"
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

/*

9   3   15  20  7


9   15  7   20  3
H   H   H
    L---R---H
L---R-----------H


4   2   5   6   1   3   8   9   7   10
L---------------H---R----------------
L---H---R----       H---R------------
H       L---H           L-------H---R
        H               H---R       H
                            H

4   5   6   2   9   8   10  7   3   1
L---------------R-------------------H
L---R-------H   R---------------H
H   L---H       L-------R---H
    H           R---H   H
                H



*/


// @lc code=start
vector<int> TTT;
using it = decltype(TTT.begin());
struct range {
    it begin, end; 
    range(it begin, it end) {this->begin=begin;this->end = end;}
    range(it begin, int len) {this->begin=begin;end = begin+len;}
    int len() {return end-begin;}
};
class Solution {
public:
    TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder) {
        return aux(
            range(inorder.begin(), inorder.end()), 
            range(postorder.begin(), postorder.end())
        );
    }

    TreeNode *aux(range inorder, range postorder) {
        if (inorder.len() == 0)
            return nullptr;
        if (inorder.len() == 1) 
            return new TreeNode(*inorder.begin);
        
        TreeNode *head = new TreeNode(*(postorder.end - 1));
        it i = inorder.begin;
        while (*(i++) != head->val);
        it ihead = i-1;

        range left_inorder = range(inorder.begin, ihead);
        range right_inorder = range(i, inorder.end);

        range left_postorder = range(postorder.begin, left_inorder.len());
        range right_postorder = range(left_postorder.end, right_inorder.len());

        head->left = aux(left_inorder, left_postorder);
        head->right = aux(right_inorder, right_postorder);

        return head;
    }
};
// @lc code=end

