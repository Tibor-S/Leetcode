#include <algorithm>
#include <iterator>
#include <string>
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

1   0   0   1   0   1   0
|   x   x   |   x   |   x

0   0   1   0   1   0   0   1
x   x   |   x   |   x   x   |
        s   i   s   i   i   i
*/

class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long total = 0;
        int len = 0;
        int i = s.size() - 1;

        for (; i >= 0; i--) {
            long long ptotal = total;
            switch (s[i]) {
                case '0': len++; break;
                case '1': 
                    ptotal |= 1 << len; 
                    if (ptotal <= k ) {
                        total = ptotal;
                        len++;
                    } 
                    break;
            }
            if (ptotal > k) break;
            if (1 << len > k) break;
        }
        if (i < 0) return len;
        auto last = s.begin();
        std::advance(last, i);
        
        return len + std::count(s.begin(), last, '0');
    }
};