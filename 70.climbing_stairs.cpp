
#include <cmath>
////////////////////////////////////////////////////////////////////////////////////////////////////


/*

x       1 way
xx      2 way
xxx     3
xxxx    5

*/


class Solution {
public:
    int climbStairs(int n) {
        int x = n + 1;
        int pos = pow((1.0 + std::sqrt(5)) / 2, x);
        int neg = pow((1.0 - std::sqrt(5)) / 2, x);
        return static_cast<int>((pos - neg) / sqrt(5));
    }
};