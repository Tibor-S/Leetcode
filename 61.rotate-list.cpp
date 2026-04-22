/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0) return head;
        if (head == nullptr) return head;
        ListNode* it = head;
        int len = 0;
        while (len < k) {
            len++;
            it = it->next;
            if (!it) break;
        }

        if (!it) return rotateRight(head, k % len);

        ListNode* end = head;
        ListNode* begin = head->next;
        ListNode* mid = it;
        ListNode* peek = it->next;

        while (peek) {
            end = end->next;
            begin = begin->next;
            mid = mid->next;
            peek = peek->next;
        }

        end->next = nullptr;
        mid->next = head;
        return begin;
    }
};
// @lc code=end

