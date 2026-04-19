#include <set>
#include <vector>
using std::vector;
using std::set;
/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ret {};
        heaps(nums.size(), nums, ret);
        return vector<vector<int>>(ret.begin(), ret.end());
    }

    void heaps(int k, vector<int> &nums, set<vector<int>> &ret) {
        if (k == 1) {
            if (!ret.contains(nums)) {
                ret.emplace(nums);
            }
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

