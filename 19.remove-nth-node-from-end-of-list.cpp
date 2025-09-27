/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
public:

    ListNode* remove(ListNode* node, int* n) {
        if (!node)
            return nullptr;

        node->next = remove(node->next, n);
        *n -= 1;
        if (!*n)
            return node->next;
        return node;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return remove(head, &n);
    }
};
// @lc code=end

