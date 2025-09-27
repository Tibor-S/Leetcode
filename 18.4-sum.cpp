#include <algorithm>
#include <set>
#include <vector>
using std::vector;
using std::set;
/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        set<vector<int>> ret;
        auto it1 = nums.begin();
        while (it1 != nums.end()) {
            auto it2 = it1;
            it2++;
            while (it2 != nums.end()) {
                auto it3 = it2;
                it3++;
                while(it3 != nums.end()) {
                    long it4 = (long)target-(long)*it1 -(long)*it2 -(long)*it3;
                    auto first = it3;
                    first++;
                    if (std::binary_search(first, nums.end(), it4))
                        ret.insert({*it1,*it2,*it3,(int)it4});

                    it3++;
                }
                it2++;
            }
            it1++;
        } 

        return vector<vector<int>>(ret.begin(),ret.end());
    }
};
// @lc code=end

