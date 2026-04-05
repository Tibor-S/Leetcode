#include <bitset>
#include <vector>
using std::vector;
using std::bitset;
/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start


class Solution {
public:
    bitset<9> row[9];
    bitset<9> col[9];
    bitset<9> grd[9];

    void solveSudoku(vector<vector<char>>& board) {
        for (int y = 0; y < 9; y++) {
            for (int x = 0; x < 9; x++) {
                int g = (y / 3) * 3 + x / 3;
                int ni = Solution::ni(board[y][x]);
                if (ni < 0)
                    continue;
                row[y][ni] = true; 
                col[x][ni] = true; 
                grd[g][ni] = true; 
            }
        }
        rec(board, 0, 0);
    }

    bool rec(vector<vector<char>>& board, int x, int y) {
        if (y == 9) return true;
        int next_x = (x + 1) % 9;
        int next_y = y;
        if (next_x == 0) next_y++;
        
        if (board[y][x] != '.') {
            return rec(board, next_x, next_y);
        }

        int g = (y / 3) * 3 + x / 3;

        bitset<9> possible = ~(row[y] | col[x] | grd[g]);
        for (int n = 0; n < 9; n++) {
            if (!possible[n]) continue;

            row[y][n] = true;
            col[x][n] = true;
            grd[g][n] = true;
            if (rec(board, next_x, next_y)) {
                board[y][x] = '0' + n + 1;
                return true;
            }
            row[y][n] = false;
            col[x][n] = false;
            grd[g][n] = false;
        }
        return false;
    }

    static int ni(char n) {
        switch (n) {
            case '1': return 1 - 1;
            case '2': return 2 - 1;
            case '3': return 3 - 1;
            case '4': return 4 - 1;
            case '5': return 5 - 1;
            case '6': return 6 - 1;
            case '7': return 7 - 1;
            case '8': return 8 - 1;
            case '9': return 9 - 1;
        }
        return -1;
    }
};
// @lc code=end

