#include <utility>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret {};
        heaps(nums.size(), nums, ret);
        return ret;
    }

    void heaps(int k, vector<int> &nums, vector<vector<int>> &ret) {
        if (k == 1) {
            ret.emplace_back(nums);
        } else {
            heaps(k-1, nums, ret);

            for (int i = 0; i < k-1; i++) {
                if ((k&1) == 0) {
                    std::swap(nums[i], nums[k-1]);
                } else {
                    std::swap(nums[0], nums[k-1]);
                }
                heaps(k-1, nums, ret);
            }
        }
    }
};
// @lc code=end

