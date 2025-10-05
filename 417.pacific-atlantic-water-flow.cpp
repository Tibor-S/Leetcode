#include <algorithm>
#include <functional>
#include <iterator>
#include <queue>
#include <set>
#include <vector>
using std::vector;
using std::set;
using std::priority_queue;

/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start

struct C {
    int row;
    int col;
    int height;
};
template<>
struct std::less<C> {
    constexpr bool operator()(const C&l, const C&r) const {
        if (l.height == r.height) {
            if (l.row == r.row)
                return l.col < r.col;
            return l.row < r.row;
        }
        return l.height < r.height;
    }
};
template<>
struct std::greater<C> {
    constexpr bool operator()(const C&l, const C&r) const {
        if (l.height == r.height) {
            if (l.row == r.row)
                return l.col > r.col;
            return l.row > r.row;
        }
        return l.height > r.height;
    }
};

class Solution {
public:
    int row_op[4] = {0, 0, -1, 1};
    int col_op[4] = {-1, 1, 0, 0};

    void process(vector<vector<int>>& heights, set<C>& ocean, 
        priority_queue<C, vector<C>, std::greater<C>>& next_flow) 
    {
        while (!next_flow.empty()) {
            C flow = next_flow.top();
            next_flow.pop();
            for (int op = 0; op < 4; op++) {
                C cell = {flow.row + row_op[op], flow.col + col_op[op]};
                if (cell.row < 0 || cell.row >= heights.size() || 
                    cell.col < 0 || cell.col >= heights[0].size()) 
                {
                    continue;
                }
                cell.height = heights[cell.row][cell.col];
                if (ocean.contains(cell))
                    continue;

                if (cell.height >= flow.height) {
                    ocean.insert(cell);
                    next_flow.push(cell);
                }
                
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.size() <= 1 || heights[0].size() <= 1) {
            vector<vector<int>> ret {};
            for (int r = 0; r < heights.size(); r++) {
                for (int c = 0; c < heights[0].size(); c++)
                    ret.push_back({r, c});
            }
            return ret;
        }
        set<C> pacific {};
        {
            priority_queue<C, vector<C>, std::greater<C>> next_flow {};
            for (int col = 0; col < heights[0].size(); col++) {
                C cell = {0, col, heights[0][col]};
                pacific.insert(cell);
                next_flow.push(cell);
            }
            for (int row = 1; row < heights.size(); row++) {
                C cell = {row, 0, heights[row][0]};
                pacific.insert(cell);
                next_flow.push(cell);
            }

            process(heights, pacific, next_flow);
        }

        set<C> atlantic {};
        {
            priority_queue<C, vector<C>, std::greater<C>> next_flow {};
            int r = heights.size()-1;
            for (int col = 0; col < heights[0].size(); col++) {
                C cell = {r, col, heights[r][col]};
                atlantic.insert(cell);
                next_flow.push(cell);
            }
            int c = heights[0].size()-1;
            for (int row = 0; row < heights.size()-1; row++) {
                C cell = {row, c, heights[row][c]};
                atlantic.insert(cell);
                next_flow.push(cell);
            }

            process(heights, atlantic, next_flow);
        }
        
        vector<C> both {};
        std::set_intersection(pacific.begin(), pacific.end(), 
            atlantic.begin(), atlantic.end(), 
            std::back_inserter(both), std::less<C>());

        vector<vector<int>> ret {};
        for (auto&c:both) {
            ret.push_back({c.row, c.col});
        }

        return ret;
    }
};
// @lc code=end

