#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret {};
        spiralOrder(0, matrix, ret);
        return ret;
    }
    void spiralOrder(int level, vector<vector<int>>& matrix, vector<int> &ret) {
        int start = level;
        int size[2] = {
            (int) matrix[0].size() - 2 * level, 
            (int) matrix.size() - 2 * level
        };
        if (size[0] == 0 || size[1] == 0) {
            return;
        }
        if (size[0] == 1) {
            for (int y = start; y < start + size[1]; y++) {
                ret.push_back(matrix[y][start]);
            }
            return;
        }
        if (size[1] == 1) {
            for (int x = start; x < start + size[1]; x++) {
                ret.push_back(matrix[start][x]);
            }
            return;
        }

        for (int x = start; x < start + size[0]; x++) {
            ret.push_back(matrix[start][x]);
        }

        for (int y = start+1; y < start + size[1]; y++) {
            ret.push_back(matrix[y][start+size[0]-1]);
        }

        for (int x = start+size[0]-2; x >= start; x--) {
            ret.push_back(matrix[start+size[1]-1][x]);
        }

        for (int y = start+size[1]-2; y >= start; y--) {
            ret.push_back(matrix[y][start]);
        }

        spiralOrder(level+1, matrix, ret);
    }
};
// @lc code=end

