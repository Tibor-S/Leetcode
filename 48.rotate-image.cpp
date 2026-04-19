#include <utility>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int N = matrix.size();

        for (int row = 0; row < N; row ++) {
            for (int col = row+1; col < N; col ++) {
                std::swap(matrix[row][col], matrix[col][row]);
            }
            for (int col = 0; col < N/2; col ++) {
                std::swap(matrix[row][col], matrix[row][N-col-1]);
            }
        }
    }
};
// @lc code=end

