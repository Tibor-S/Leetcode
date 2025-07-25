#include <algorithm>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto begin = std::upper_bound(nums.begin(), nums.end(), 0);
        if (begin == nums.end()) return *(--begin);


        int s = 0;
        while (begin != nums.end()) {
            s += *begin;
            begin = std::upper_bound(begin, nums.end(), *begin);
        }
        return s;
    }
};