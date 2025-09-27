#include <functional>
#include <queue>
#include <vector>
using std::vector;
using std::priority_queue;
/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start

template<>
struct std::greater<ListNode*> {
    constexpr bool operator()(const ListNode*l, const ListNode*r) const {
        return l->val > r->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, std::greater<ListNode*>> prio {};

        for (ListNode* el : lists) {
            if (el)
                prio.push(el); 
        }
        if (prio.empty())
            return nullptr;

        auto ret = new ListNode(prio.top()->val);
        ListNode* rest = prio.top()->next;
        prio.pop();
        if (rest)
            prio.push(rest);
        auto append_to = ret;
        while (!prio.empty()) {
            append_to->next = new ListNode(prio.top()->val);
            append_to = append_to->next;
            ListNode* rest = prio.top()->next;
            prio.pop();
            if (rest)
                prio.push(rest);
        }

        return ret;
    }
};
// @lc code=end

