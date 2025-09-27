#include <cstdlib>
#include <functional>
/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648 && divisor == -1)
            return 2147483647;
        if (dividend == -2147483648 && divisor == 1)
            return -2147483648;
        bool neg = (divisor < 0) ^ (dividend < 0);
        long dividend_l = std::abs((long)dividend);
        long divisor_l = std::abs((long)divisor);
        if (divisor_l == 1)
            return neg ? std::negate<long>()(dividend_l) : dividend_l;
        if (divisor_l == 2)
            return neg ? std::negate<long>()(dividend_l>>1) : dividend_l>>1;
        long res = 0;
        long n = 0;
        while (n <= dividend_l) {
            res++;
            n += divisor_l;
        }
        res--;
        return neg ? std::negate<long>()(res) : res;
    }
};
// @lc code=end

