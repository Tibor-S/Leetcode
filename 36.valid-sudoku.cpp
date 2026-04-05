#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][10] = {};
        int cols[9][10] = {};
        int grid[9][10] = {};

        for (int y = 0; y < 9; y++) {
            for (int x = 0; x < 9; x++) {
                int g = (y / 3) * 3 + x / 3;
                int ni = Solution::ni(board[y][x]);
                if (!ni)
                    continue;
                if (rows[y][ni]++ > 0) return false; 
                if (cols[x][ni]++ > 0) return false; 
                if (grid[g][ni]++ > 0) return false; 
            }
        }

        return true;
    }

    static int ni(char n) {
        switch (n) {
            case '1': return 1;
            case '2': return 2;
            case '3': return 3;
            case '4': return 4;
            case '5': return 5;
            case '6': return 6;
            case '7': return 7;
            case '8': return 8;
            case '9': return 9;
        }
        return 0;
    }
};
// @lc code=end

