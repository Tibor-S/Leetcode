/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        if (head->val == head->next->val) {
            int v = head->val;
            while (head && head->val == v)
                head = head->next;
            return deleteDuplicates(head);
        } else {
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};
// @lc code=end

