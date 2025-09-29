#include <cstdint>
#include <iterator>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 */



// @lc code=start
class Solution {
public:
    vector<int>* t;
    using I = decltype(t->begin());

    int mem[50][50] = {};

    int mn_rec(I first, I last) {
        if (std::distance(first, last) + 1 < 3)
            return 0;
        if (std::distance(first, last) + 1 == 3)
            return *(first++) * *(first++) * *(first++);
        if (mem[std::distance(t->begin(), first)][std::distance(t->begin(), last)]) {
            return mem[std::distance(t->begin(), first)][std::distance(t->begin(), last)];
        }

        int mn = INT32_MAX;
        I k = first;
        k++;

        while (k != last) {
            int mid = *first * *k * *last;
            int left = mn_rec(first, k);
            int right = mn_rec(k, last);
            mn = std::min(left + mid + right, mn);
            k++;
        }
        mem[std::distance(t->begin(), first)][std::distance(t->begin(), last)] = mn;
        return mn;
    }

    int minScoreTriangulation(vector<int>& values) {
        t = &values;
        I last = values.end();
        return mn_rec(values.begin(), --last);
    }
};
// @lc code=end

