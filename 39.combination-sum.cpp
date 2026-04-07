#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

/*
2   3   6   7   sum     ci  op
0   0   0   0   0       0   i0
1   0   0   0   2       0   i0
2   0   0   0   4       0   i0
3   0   0   0   6       0   i0
4   0   0   0   8       0   i0
0   1   0   0   3       0   i1 r0
1   1   0   0   5       0   i0
2   1   0   0   7   x   0   i0
0   2   0   0   7   x   0   i0
0   0   1   0   6           i2 r1 r0
1   0   1   0   8           i0
0   1   1   0   9           i1 r0
0   0   0   1   7   x       i3 r2 r1 r0


*/


// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> freq(candidates.size());
        int sum = 0;
        while (true) {
            int ci = 0;
            for (; ci < candidates.size(); ci++) {
                freq[ci]++;
                sum += candidates[ci];
                
                if (sum < target) {
                    break;
                } else if (sum == target) {
                    push(ret, candidates, freq);
                }
                sum -= freq[ci] * candidates[ci];
                freq[ci] = 0;
            }
            if (ci == candidates.size()) {
                break;
            }
        }
        
        return ret;
    }
    void push(vector<vector<int>> &ret, vector<int> &candidates, vector<int> &freq) {
        ret.emplace_back();
        for (int i = 0; i < candidates.size(); i++) {
            for (int j = 0; j < freq[i]; j++) {
                ret.back().push_back(candidates[i]);
            }
        }
    }
};
// @lc code=end

