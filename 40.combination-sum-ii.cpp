#include <algorithm>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

/*
LEN: 4

10  1   2   7   6   1   5

*/


// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        
        std::sort(candidates.begin(), candidates.end());

        vector<int> his {};
        rec(ret, candidates, target, his, 0, 0);

        return ret;
    }

    void rec(
        vector<vector<int>> &ret, 
        vector<int> &candidates, 
        int target,
        vector<int> &history, 
        int sum,
        int ci
    ) {
        if (ci == candidates.size())
            return;
        
        int curr = candidates[ci];
        int next_ci = ci + 1;
        history.push_back(curr);
        sum += curr;
        while (next_ci < candidates.size() && candidates[ci] == candidates[next_ci]) {
            history.push_back(curr);
            next_ci++;
            sum += curr;
        }

        for (int count = next_ci - ci; count > 0; count--) {
            if (sum == target) {
                ret.emplace_back(history);
            } else if (sum < target) {
                rec(ret, candidates, target, history, sum, next_ci);
            }
            history.pop_back();
            sum -= curr;
        }
        if (sum == target) {
            ret.emplace_back(history);
        } else if (sum < target) {
            rec(ret, candidates, target, history, sum, next_ci);
        }

    }
};
// @lc code=end

