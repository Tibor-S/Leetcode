#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

y\x 0   1   2
0   1   4   5
1   2   7   6
2   6

1   3   6
5   8   12


*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 1; i < grid[0].size(); i++) {
            grid[0][i] += grid[0][i-1];
        }
        for (int i = 1; i < grid.size(); i++) {
            grid[i][0] += grid[i-1][0];
        }

        for (int y = 1; y < grid.size(); y++) {
            for (int x = 1; x < grid[0].size(); x++) {
                grid[y][x] += std::min(grid[y][x-1], grid[y-1][x]);
            }
        }

        return grid.back().back();
    }
};