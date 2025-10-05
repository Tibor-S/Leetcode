#include <algorithm>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

/*

2   3   4   5
2   3   5   4
2   4   3   5
2   4   5   3
2   5   3   4
2   5   4   3

3   2   4   5
3   2   5   4
3   4   2   5
3   4   5   2
3   5   2   4
3   5   4   2

4   2   3   5
4   2   5   3
4   3   2   5
4   3   5   2
4   5   2   3
4   5   3   2

5   2   3   4
5   2   4   3
5   3   2   4
5   3   4   2
5   4   2   3
5   4   3   2
*/

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto pivot = nums.end();
        int after = *(--pivot);
        while ((pivot--) != nums.begin()) {
            int val = *pivot;
            if (val < after) {
                auto swap = pivot;
                auto it = ++swap;
                while (++it != nums.end()) {
                    if (*it > val && *it < *swap) {
                        swap = it;
                    }
                }
                int t = *pivot;
                *pivot = *swap;
                *swap = t;
                break;
            }
            after = *pivot;
        }
        std::sort(++pivot, nums.end());
        return;
    }
};
// @lc code=end

