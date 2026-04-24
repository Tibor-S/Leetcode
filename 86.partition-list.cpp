/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lt_head = nullptr;
        ListNode *lt_last = nullptr;
        ListNode *ge_head = nullptr;
        ListNode *ge_last = nullptr;

        ListNode *it = head;
        while (it) {
            if (it->val < x) {
                if (!lt_head) {
                    lt_head = it;
                } else {
                    lt_last->next = it;
                }
                lt_last = it;
                it = it->next;
                lt_last->next = nullptr; 
            } else {
                if (!ge_head) {
                    ge_head = it;
                } else {
                    ge_last->next = it;
                }
                ge_last = it;
                it = it->next;
                ge_last->next = nullptr; 
            }
        }
        
        if (lt_head) {
            lt_last->next = ge_head;
            return lt_head;
        } else {
            return ge_head;
        }
    }
};
// @lc code=end

