#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

3   5   6   7
x           x

2   3   3   4   6   7
x                       1
x   x                   2
x       x               4
x           x           8   
x               x       16
x                   x   32
    x                   33
    x   x               34
    x       x           36
    x           x       40
    x               x   48
        x               59
        x   x           50
        x       x       52
        x           x   56
            x           57
            x   x       58
            x       x   60
                x       61
                
target = 9
                    M
0   1   2   3   4   5   6   7   8   9   10  11  12  13
F                                   L
    F                           L
        F                   L
            F           L
                F   L
                    FL
*/

class Solution {
public:
    long long mod_pow(long long b, int exp) {
        int r = 1;
        while (exp > 0) {
            if (exp & 1) {
                r = (r * b) % 1000000007;
            }
            exp >>= 1;
            b = (b * b) % 1000000007;
        }

        return r;
    }

    int numSubseq(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int s;
        long long i;
        int exp;

        auto minlast = std::upper_bound(nums.begin(), nums.end(), target >> 1);
        if (minlast == nums.begin()) return 0;
        auto first = --minlast;
        auto maxlast = std::upper_bound(first, nums.end(), target - *first);;
        exp = std::distance(first, maxlast) - 1;
        s = i = mod_pow(2, exp);
        while (first-- != nums.begin()) {
            maxlast = std::upper_bound(maxlast, nums.end(), target - *first);
            i = (mod_pow(2, std::distance(first, maxlast) - 1 - exp) * i) % 1000000007;
            exp = std::distance(first, maxlast) - 1;
            s += i;
            s %= 1000000007;
        }

        return s;
    }
};