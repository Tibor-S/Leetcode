#include <algorithm>
#include <string>
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////


/*

n - i - j + i + j = n

*/

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long s = 0;
        for (long long i = 0; i <= std::min(n,limit); i++) {
            s += std::max(std::min((long long)limit, n-i) - std::max((long long)0, n - i - limit) + 1, (long long)0);
        }
        return s;
    }
};