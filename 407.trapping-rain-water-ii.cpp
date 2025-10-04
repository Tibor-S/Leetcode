#include <cstddef>
#include <functional>
#include <queue>
#include <unordered_set>
#include <vector>
using std::vector;
using std::unordered_set;
using std::priority_queue;

/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 */

/*

*/

// @lc code=start
struct Cell {
    int row, col, height;
};

template<>
struct std::greater<Cell> {
    constexpr bool operator()(const Cell&l,const Cell&r) const {
        return l.height > r.height;
    }
};

template<>
struct std::equal_to<Cell> {
    constexpr bool operator()(const Cell&l,const Cell&r) const {
        return l.col == r.col && l.row == r.row;
    }
};

template<>
struct std::hash<Cell> {
    size_t operator()(const Cell&c) const noexcept {
        return std::hash<int>{}(c.row) ^ (std::hash<int>{}(c.col) << 1);
    }
};

class Solution {
public:
    int w, h;
    priority_queue<Cell, vector<Cell>, std::greater<Cell>> mn_wall {};
    unordered_set<Cell> visited {};
    int before = 0, after = 0;

    void init(vector<vector<int>>& heightMap) {
        int row = 0;
        for (int col = 0; col < heightMap[0].size(); col++) {
            Cell cell = {row, col, heightMap[row][col]};
            mn_wall.push(cell);
            visited.insert(cell);
        }
        row++;
        for (; row < heightMap.size()-1; row++) {
            Cell cell1 = {row, 0, heightMap[row][0]};
            Cell cell2 = {row, (int)heightMap[0].size()-1, heightMap[row][heightMap[0].size()-1]};
            mn_wall.push(cell1);
            mn_wall.push(cell2);
            visited.insert(cell1);
            visited.insert(cell2);
        }
        for (int col = 0; col < heightMap[0].size(); col++) {
            Cell cell = {row, col, heightMap[row][col]};
            mn_wall.push({row, col, heightMap[row][col]});
            visited.insert(cell);
        }
    }

    void visit(vector<vector<int>>& heightMap, int row, int col, int wall) {
        if (row < 0 || row >= h || col < 0 || col >= w)
            return;
        int height = heightMap[row][col];
        Cell cell = {row, col, std::max(height, wall)};
        if (visited.contains(cell))
            return;
        before += height;
        after += cell.height;
        mn_wall.push(cell);
        visited.insert(cell);
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        w = heightMap[0].size();
        h = heightMap.size();
        if (w <= 2) return 0;
        if (h <= 2) return 0;
        init(heightMap);
        while (!mn_wall.empty()) {
            Cell wall = mn_wall.top();
            mn_wall.pop();
            visit(heightMap, wall.row, wall.col-1, wall.height);
            visit(heightMap, wall.row, wall.col+1, wall.height);
            visit(heightMap, wall.row-1, wall.col, wall.height);
            visit(heightMap, wall.row+1, wall.col, wall.height);
        }

        return after - before;
    }
};
// @lc code=end

