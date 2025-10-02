/*
 * @lc app=leetcode id=3100 lang=cpp
 *
 * [3100] Water Bottles II
 */

// @lc code=start
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = numBottles;
        int full = 0;
        int tot = numBottles;
        while (empty >= numExchange) {
            empty -= numExchange;
            full++;
            numExchange++;
            if (empty < numExchange) {
                tot += full;
                empty += full;
                full = 0;
            }
        }
        return tot;
    }
};
// @lc code=end

