#include <cmath>
////////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    int fib(int n) {
        double pos = pow((1.0 + std::sqrt(5)) / 2, n);
        double neg = pow((1.0 - std::sqrt(5)) / 2, n);
        return static_cast<int>((pos - neg) / sqrt(5));
    }
};