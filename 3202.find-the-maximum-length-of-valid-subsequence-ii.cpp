#include <algorithm>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////


/*

    1   2   3   4   5   6   7
1   2   0   1   2   0   1   2
2   0   1   2   0   1   2   0
3   1   2   0   1   2   0   1
4   2   0   1   2   0   1   2
5   0   1   2   0   1   2   0
6   1   2   0   1   2   0   1
7   2   0   1   2   0   1   2

k = 1
0   0

k = 2
0:
0   0
1   1

0:
0       0
1       2
2       1

1:
0       1
1       0
2       2

1       2   5
2       1   4   7
3       3   6
4       2   5
5       1   4   7
6       3   6
7       2   5

mod 4:
0:
0   0
1   3
2   2
3   1

1:
0   1
1   0
2   3
3   2

mod 5:
0:
0   0
1   4
2   3
3   2
4   1


k = 3
dp\k0   1   2
1   0   1   0
4   
2
3
1
4


x = mod - n

*/

class Solution {
public:
    int mxx(vector<int>& nums, int k, int mod) {
        vector<int> len(k,0);
        for (int n : nums) {
            n %= k;
            int x = mod - n;
            if (x < 0) x += k;
            len[n] = std::max(len[x] + 1, len[n]);
        }

        int mx = 0;
        for (int l : len) mx = std::max(l, mx);
        return mx;
    }

    int maximumLength(vector<int>& nums, int k) {
        int mx = 0;
        for (int mod = 0; mod < k; mod++) mx = std::max(mxx(nums, k, mod), mx);
        return mx;   
    }
};