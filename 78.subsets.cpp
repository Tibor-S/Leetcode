#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret(1 << nums.size(), vector<int>(0));
        place(0, nums, ret);
        return ret;
    }

    int place(int i, vector<int>& nums, vector<vector<int>> &ret) {
        if (i == nums.size()) {
            return 1;
        }
        int len = place(i+1, nums, ret);
        for (int j = 0; j < len; j++) {
            ret[len+j] = vector<int>(ret[j]);
            ret[len+j].push_back(nums[i]);
        }
        return 2*len;
    }
};
// @lc code=end

