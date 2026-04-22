#include <string>
using std::string;
/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        string ret = "";
        int collection[] {
            1,2,3,4,5,
            6,7,8,9
        };
        for (int i = n-1; i >= 0; i--) {
            int fi = fac(i);
            int base = k / fi;
            k -= base * fi;
            ret.push_back('0' + collection[base]);
            for (int j = base; j < 8; j++)
                collection[j] = collection[j+1];
        }

        return ret;
    }

    const int fac(int i) {
        int prod = 1;
        for (int j = 1; j <= i; j++)
            prod *= j;
        return prod;
    }
};
// @lc code=end

