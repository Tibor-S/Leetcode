#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

i/j 0   1   2   3   4   5   6   7
0   s               x
1           x   
2                       x
3       x
4                               e

i/j 0   1   2
0   s   1
1   1   x   
2           e


*/



class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.front().front() == 1) return 0;

        for (int x = 0; x < obstacleGrid[0].size(); x++) {
            if (obstacleGrid[0][x] == 1) { 
                for (int r = x; r < obstacleGrid[0].size(); r++) obstacleGrid[0][r] = 0;
                break;
            }
            obstacleGrid[0][x] = 1; 
        }

        for (int y = 1; y < obstacleGrid.size(); y++) {
            if (obstacleGrid[y][0] == 1) { 
                for (int r = y; r < obstacleGrid.size(); r++) obstacleGrid[r][0] = 0;
                break;
            }
            obstacleGrid[y][0] = 1;
        }

        for (int y = 1; y < obstacleGrid.size(); y++) {
            for (int x = 1; x < obstacleGrid[0].size(); x++) {
                obstacleGrid[y][x] = obstacleGrid[y][x] != 1 ? obstacleGrid[y-1][x] + obstacleGrid[y][x-1] : 0; 
            }
        }

        return obstacleGrid.back().back();
    }
};