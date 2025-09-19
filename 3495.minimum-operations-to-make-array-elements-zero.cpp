#include <algorithm>
#include <array>
#include <iterator>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

l\r 1   2   3   4   5   6   7   8   16
1   1   1   2   3   4   5   6   7
2   
3   
4   
5   
6   

bin     ds  
000001  1
000010  1
000100  2
001000  2
010000  3
100000  3

ds  in set
1   100 - 1     = 11    = 3
2   10000 - 100 = 1100  = 12
3   48
4   192

rem_cost, odd count
a   b   c   d   e
3   3   3   3   3
2   2   3   3   3
2   2   2   2   3
1   2   2   2   2
1   1   1   2   2
1   1   1   1   1
0   0   1   1   1
0   0   0   0   1
0   0   0   0   0


rc for:
6   7   8
2   2   2
1   1   2
0   1   1
0   0   0

*/


class Solution {
public:
    std::array<int, 16> groups {
        0x1, 0x4, 0x10, 0x40,
        0x100, 0x400, 0x1000, 0x4000,
        0x10000, 0x40000, 0x100000, 0x400000,
        0x1000000, 0x4000000, 0x10000000, 0x40000000,
    };

    long long minOperations(vector<int>& query) {
        long long total = 0;
        int gsi = std::distance(
            groups.begin(),
            std::upper_bound(groups.begin(), groups.end(), query[0]) 
        );
        int gei = -1 + std::distance(
            groups.begin(),
            std::upper_bound(groups.begin(), groups.end(), query[1]) 
        );

        // two cases;
        // Q[0] < groups[gsi] <= groups[gei] <= Q[1]
        // groups[gei] <= Q[0] < Q[1] < groups[gsi]

        long long rem_cost[2] = {gsi, gei + 1};

        if (gsi <= gei) {
            long long cnt[2] = {
                groups[gsi] - query[0],
                query[1] + 1 - groups[gei] 
            };
            long long ops[2] = {
                (cnt[0] * rem_cost[0]) / 2,
                (cnt[1] * rem_cost[1]) / 2
            };
            long long rem[2] = {
                (cnt[0] * rem_cost[0]) & 1,
                (cnt[1] * rem_cost[1]) & 1
            };
            for (int i = gsi; i < gei; i++) {
                long long rem_cost = i + 1;
                long long cnt = 0b11 << (2 * i);
                total += (cnt * rem_cost) / 2;
            }
            total += ops[0] + ops[1];
            if (rem[0] || rem[1]) total++;
        } else {
            long long cnt = query[1] + 1 - query[0];
            total += (cnt * rem_cost[0]) / 2;
            if ((cnt * rem_cost[0]) & 1) total++;
        }

        return total;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long s = 0;
        for (auto& q: queries) s+=minOperations(q);
        return s;
    }

};