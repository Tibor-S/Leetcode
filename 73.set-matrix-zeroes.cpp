#include <bitset>
#include <vector>
using std::vector;
using std::bitset;

/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bitset<200> in_cols;
        bitset<200> in_rows;

        for (int y = 0; y < matrix.size(); y++) {
            for (int x = 0; x < matrix[0].size(); x++) {
                if (!matrix[y][x]) {
                    in_cols[x] = true;
                    in_rows[y] = true;
                }
            }
        }
        if (in_cols == 0) return;
        for (int y = 0; y < matrix.size(); y++) {
            if (in_rows[y]) {
                for (int x = 0; x < matrix[0].size(); x++)
                    matrix[y][x] = 0;
            }
            for (int x = 0; x < matrix[0].size(); x++) {
                if (in_cols[x]) {
                    matrix[y][x] = 0;
                }
            }
        }
    }
};
// @lc code=end

