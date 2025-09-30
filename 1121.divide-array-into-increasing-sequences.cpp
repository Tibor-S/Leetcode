#include <queue>
#include <vector>
using std::vector;
using std::priority_queue;

/*
 * @lc app=leetcode id=1121 lang=cpp
 *
 * [1121] Divide Array Into Increasing Sequences
 */

/*

1   2   2   3   3   4   4
1   2   2   3   3   4   4
        1   1   2   2   3

k = 3
1   2   2   2

k = 3
1   1   1   2
1   2   2


k = 2
1   1   2
2   2

*/


// @lc code=start
class Solution {
public:

    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        priority_queue<int> l_len {};
        int pre = nums[0];
        int c = 1;
        for (int i = 1; i < nums.size(); i++) {
            int n = nums[i];
            if (n == pre) {
                c++;
            } else {
                l_len.push(c);
                pre = n;
                c = 1;
            }
        }
        l_len.push(c);

        // Are there enough of neediest
        int largest = l_len.top();
        int count_largest = 0;
        while (!l_len.empty() && l_len.top() == largest) {
            count_largest++;
            l_len.pop();
        }

        if (count_largest >= k)
            return true;

        int still_needed = k - count_largest;
        int acc = 0;
        while (!l_len.empty() && still_needed > 0) {
            acc += l_len.top();
            l_len.pop();
            if (acc >= largest) {
                acc -= largest;
                still_needed--;
            }
        }

        return still_needed == 0;
    }
};
// @lc code=end

