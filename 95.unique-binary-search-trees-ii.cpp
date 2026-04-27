#include <vector>
#include "treenode.h"
using std::vector;
/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */


/*
Len 1:
1:  1
2:  2
3:  3
4:  4

Len 2:
1-2:
    2.i:
        1
            2
    2.ii:
            2
        1

2-3:
    2.i:
        2
            3
    2.ii:
            3
        2

3-4:
    2.i:
        3
            4
    2.ii:
            4
        3

Len 3:

1-2-3:
    3.i
        1
            2.i
    3.ii
        1
            2.ii
    3.iii
            2
        1       3
    3.iv
            3
        2.i
    3.v
            3
        2.ii
    
2-3-4:
    3.i
        2
            3.i
    3.ii
        2
            3.ii
    3.iii
            3
        2       4
    3.iv
            4
        2.i
    3.v
            4
        2.ii

Len 4:
    4.i
        1
            3.i
*/

// @lc code=start
#define NNV {}
#define NNV2 NNV, NNV
#define NNV4 NNV2, NNV2
#define NNV8 NNV4, NNV4
#define NV(i) {new TreeNode(i)}
#define NV2(i) NV(i), NV(i+1)
#define NV4(i) NV2(i), NV2(i+2)
#define NV8(i) NV4(i), NV4(i+4)
#define NC {{NV8(1)}, {NNV8}, {NNV8}, {NNV8}, {NNV8}, {NNV8}, {NNV8}, {NNV8}}
class Solution {
public:
    int N;
    vector<TreeNode*> combs[8][8] NC;
    vector<TreeNode*> generateTrees(int n) {
        N = n;
        aux(n-1);
        return combs[N-1][0];
    }

    void aux(int n) {
        int len = n + 1;
        if (!n)
            return;
        
        aux(n-1);


        for (int left = 0; left < N-n; left++)
            construct_all(left, len);
    }

    void construct_all(int left, int len) {
        for (int left_len = 0; left_len < len; left_len++)
            construct_some(left, left_len, len);
    }

    void construct_some(int left, int left_len, int len) {
        int right_len = len - left_len - 1;
        int head = left + left_len;
        int right = head + 1;
        if (!right_len) {
            for (auto node : combs[left_len - 1][left]) {
                combs[len - 1][left].push_back(
                    new TreeNode(head+1, deep_copy(node), nullptr)
                );
            }
            return;
        }
        if (!left_len) {
            for (auto node : combs[right_len - 1][right]) {
                combs[len - 1][left].push_back(
                    new TreeNode(head+1, nullptr, deep_copy(node))
                );
            }
            return;
        }

        for (auto lnode : combs[left_len - 1][left]) {
            for (auto rnode : combs[right_len - 1][right]) {
                combs[len - 1][left].push_back(
                    new TreeNode(head+1, deep_copy(lnode), deep_copy(rnode))
                );
            }
        }

    }

    TreeNode* deep_copy(TreeNode *root) {
        if (!root) 
            return nullptr;

        return new TreeNode(
            root->val, 
            deep_copy(root->left), 
            deep_copy(root->right)
        );
    }
};
// @lc code=end

