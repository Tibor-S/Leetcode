#include "listnode.h"
/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        return aux(head, left-1, right-left+1);
    }

    ListNode* aux(ListNode *it, int index, int len) {
        if (index) {
            it->next = aux(it->next, index-1, len);
            return it;
        } else {
            ListNode *tt = nullptr;
            return aux_reverse(it, nullptr, len, &tt);
        }
    }

    ListNode* aux_reverse(ListNode *head, ListNode* push, int len, ListNode **new_tail) {
        if (!len) {
            *new_tail = head;
            return push;
        }

        ListNode *tail = head->next;
        head->next = nullptr;
        ListNode *new_head = aux_reverse(tail, head, len - 1, new_tail);
        if (push) {
            head->next = push;
            return new_head;
        } else {
            head->next = *new_tail;
            return new_head;
        }
    }
};
// @lc code=end

