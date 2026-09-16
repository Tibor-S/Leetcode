#include <algorithm>
#include <vector>
using std::vector;
using std::min;
using std::max;

/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int profit = 0;

        for (int i = 1; i< prices.size(); i++) {
            mn = min(prices[i], mn);
            profit = max(prices[i] - mn, profit);
        }

        return profit;
    }
};
// @lc code=end

