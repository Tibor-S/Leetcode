#include <string>
using std::string;

/*
 * @lc app=leetcode id=2209 lang=cpp
 *
 * [2209] Minimum White Tiles After Covering With Carpets
 */

/*
cl = 2
nc = 2
c   1   0   1   1   0   1   0   1
0   5   4   4   3   2   2   1   1
1   3   2   2i  2   1   1   0i  0    
2   2   1   1i  1   0i  0   0   0

*/

// @lc code=start
class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int floor_len = floor.length(), n_carpets = numCarpets, carpet_len = carpetLen;
        if (floor_len <= n_carpets * carpet_len) return 0;
        int dp[2][1000] = {};
        int total = 0;
        for (int i = floor_len -1; i >= 0; i--) {
            if (floor[i] == '1')
                total++;
            dp[0][i] = total;
        }

        for (int src = 0, dst = 1; src < n_carpets; src++, dst++) {
            int start = floor_len - dst * carpet_len;
            dp[dst&1][start] = 0;
            for (int i = start-1; i >= 0; i--) {
                int white_ex = floor[i]=='1';
                int keep_placement = dp[dst&1][i+1] + white_ex;
                int change_placement = dp[src&1][i+carpet_len];
                if (change_placement < keep_placement) {
                    dp[dst&1][i] = change_placement;
                } else {
                    dp[dst&1][i] = keep_placement;
                }
            }
        }

        return dp[n_carpets&1][0];
    }
};
// @lc code=end
