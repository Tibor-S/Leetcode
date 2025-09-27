#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    vector<ListNode*> hold;

    ListNode* prop(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* real_head = head;
        for (int i = 0; i < k; i++) {
            if (!curr) return real_head;
            hold[i] = curr;
            curr = curr->next;
        }
        real_head = hold.back();
        ListNode* last = hold.front();
        last->next = real_head->next;
        for(int i = 1; i < k; i++) {
            hold[i]->next = hold[i-1];
        }
        last->next = prop(last->next, k);
        return real_head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        hold = vector<ListNode*>(k);

        return prop(head, k);
    }
};
// @lc code=end

