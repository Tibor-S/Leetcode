#include <algorithm>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ret {};
        place(0, nums, ret);
        return ret;
    }

    void place(int i, vector<int>& nums, vector<vector<int>> &ret) {
        if (i == nums.size()) {
            ret.emplace_back();
            return;
        }
        int k = i+1;
        while (k < nums.size() && nums[i] == nums[k]) 
            k++;

        place(k, nums, ret);
        int len = ret.size();
        for (int j = 0; j < len; j++) {
            ret.emplace_back(ret[j]);
            ret.back().push_back(nums[i]);
            for (int m = i+1; m < k; m++) {
                ret.emplace_back(ret.back());
                ret.back().push_back(nums[i]);
            }
        }
    }
};
// @lc code=end

