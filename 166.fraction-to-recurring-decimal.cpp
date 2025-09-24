#include <cstdlib>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using std::string;
using std::vector;
using std::stringstream;

/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
class Solution {
public:
    /*
                  decimals...[numerator/denominator]
    denominator | 0.0..0[numerator]
                -       [return]
    
    */
    long long_div(long numerator, long denominator, vector<long> &decimals) {
        long d = numerator / denominator;
        decimals.push_back(d);
        return d * denominator;
    }

    std::unordered_map<long, int> numerator_index {};
    // returns numerator where repeating begins
    long op_with_repeating(long numerator, long denominator, vector<long> &decimals) {
        while (numerator && !numerator_index.contains(numerator)) {
            numerator_index[numerator] = decimals.size();
            numerator -= long_div(numerator, denominator, decimals);
            numerator *= 10;
        }
        return numerator;
    }

    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        bool is_neg = (numerator < 0) ^ (denominator < 0);
        vector<long> decimals {}; // decimals[0] is whole number part
        long numerator2 = numerator;
        numerator2 = abs(numerator2);
        long denominator2 = denominator;
        denominator2 = abs(denominator2);
        numerator2 -= long_div(numerator2, denominator2, decimals); // set whole part
        numerator2 *= 10;
        int tnum = op_with_repeating(
            numerator2, 
            denominator2, 
            decimals);
        bool has_repeating = tnum != 0;
        int ti = numerator_index[tnum];

        stringstream out {};
        if (is_neg) 
            out << '-';
        out << decimals[0];
        if (decimals.size() == 1) 
            return out.str();
        out << '.';
        for (int i = 1; i < decimals.size(); i++) {
            if (has_repeating && i == ti) 
                out << '(';
            out << decimals[i];
        }
        if (has_repeating)
            out << ')';
        return out.str();
    }
};
// @lc code=end

