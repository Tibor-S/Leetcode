#include <array>
#include <cstddef>
#include <functional>
#include <queue>
#include <unordered_set>
#include <vector>
using std::vector;
using std::unordered_set;
using std::priority_queue;
using std::array;
/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */

// @lc code=start
struct V {
    int x, y, val;
    V(int x, int y, int val) : x(x), y(y), val(val) {}
    V(const V&src, int dx, int dy) : x(src.x+dx), y(src.y+dy) {}
};
struct H {
    size_t operator()(const V& v) const noexcept {
        return std::hash<int>()(v.x) ^ (std::hash<int>()(v.y) << 1);
    }
};
struct E {
    constexpr bool operator()(const V& lhs, const V& rhs) const 
    {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};
struct G {
    constexpr bool operator()(const V& lhs, const V& rhs) const 
    {
        return lhs.val > rhs.val; // assumes that the implementation handles pointer total order
    }
};


class Solution {
public:
    unordered_set<V, H, E> visited {};
    priority_queue<V, vector<V>, G> next {};
    int width, height;
    

    void with_cost(const V& src, V& dst) {
        dst.val = std::max(src.val, dst.val);
    }

    void add(const vector<vector<int>>& grid, const V& src) {
        array<array<int, 2>, 4> ops {-1, 0, 1, 0, 0, -1, 0, 1};

        for (auto&op:ops) {
            V dst(src, op[0], op[1]);
            if (dst.x < 0 || dst.y < 0 || dst.x >= width || dst.y >= height)
                continue;
            if (visited.contains(dst))
                continue;
            dst.val = grid[dst.y][dst.x];
            with_cost(src, dst);
            next.push(dst);
        }
    }

    int swimInWater(vector<vector<int>>& grid) {
        width = grid[0].size(); height = grid.size();
        next.emplace(0, 0, grid[0][0]);

        while (!(next.top().x == width-1 && next.top().y == height-1)) {
            V u = next.top();
            next.pop();
            if (visited.contains(u))
                continue;
            visited.insert(u);
            add(grid, u);
        }

        return next.top().val;
    }
};
// @lc code=end

