#include <string>
using std::string;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int ret = 0;
    int getDecimalValue(ListNode* head) {

        for (; head; head = head->next) {
            ret = (ret << 1) + head->val;
        }

        return ret;
    }
};