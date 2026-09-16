#include <algorithm>
#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

/*

7   1   5   3   6   4
---------   ---------
-----   -   B---S   -
----B---S   B---S----
----B---S---B---S----

93	73	24	6	77	95	55	15	69	52	83	27	97	67	10	38	25	9	3	33
            B       S       B   S   B   S   B   S       B   S           B   S
*/



// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++){
            profit += std::max(prices[i] - prices[i-1], 0);
        }
        return profit;
    }
};
// @lc code=end

