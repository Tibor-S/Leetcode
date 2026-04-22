#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int N) {
        vector<vector<int>> ret {};

        for (int i = 0; i < N; i++)
            ret.emplace_back(N);

        generateMatrix(0, 1, ret);

        return ret;
    }

    void generateMatrix(int lvl, int st, auto& ret) {
        int N = ret.size();
        if (lvl == N) return;
        for (int x = lvl; x < N - lvl; x++) 
            ret[lvl][x] = st++;
        
        for (int y = lvl+1; y < N - lvl; y++) 
            ret[y][N-lvl-1] = st++;

        for (int x = N-lvl-2; x >= lvl; x--) 
            ret[N-lvl-1][x] = st++;

        for (int y = N-lvl-2; y > lvl; y--) 
            ret[y][lvl] = st++;

        generateMatrix(lvl+1,st,ret);
    }

};
// @lc code=end

