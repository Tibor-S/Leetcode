#include "listnode.h"
#include "treenode.h"
/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

/*

            1   
        2   
            3   
    4   
            5   
        6   
            7   
8   
            9   
        10  
            11  
    12  
            13  
        14  
            15


                        1   
                    2   
                        3   
                4   
                    5   
            6       
                7   
        8   
            9   
    10  
        11  
12  
        13  
    14  
        15


                            1   
                        2   
                            3   
                    4   
                        5   
                6       
                    7   
            8   
                9   
        10  
            11  
    12  
        13  
14  
    15

1
    2
        3
            4
                5   
                    6
                        7
                            8
                                        9
                                    10
                                        11
                                12
                                        13
                                    14
                                        15


*/

// @lc code=start
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return build(head, count(head));
    }

    int count(ListNode *head) {
        return head ? count(head->next) + 1 : 0;
    } 

    TreeNode *build(ListNode *first, int count) {
        if (!count) return nullptr;
        if (count == 1) return new TreeNode(first->val);
        if (count == 2) return new TreeNode(
            first->val,
            nullptr,
            new TreeNode(first->next->val)
        );

        int left_count = (count - 1) / 2;
        int right_count = count - left_count - 1;
        int head_offset = left_count;
        ListNode *left_first = first;
        ListNode *head = first;
        while (head_offset--) {head = head->next;}
        ListNode *right_first = head->next;

        TreeNode *root = new TreeNode(
            head->val,
            build(left_first, left_count),
            build(right_first, right_count)
        );

        return root;
    }
};
// @lc code=end

