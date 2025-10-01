/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

// @lc code=start
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = numBottles;
        int full = 0;
        int tot = numBottles;
        while (empty >= numExchange) {
            full = empty / numExchange;
            tot += full;
            empty += full - full * numExchange;
        }
        return tot;
    }
};
// @lc code=end

