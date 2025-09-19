#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int mx = 0;
        std::sort(nums.begin(), nums.end());
        auto begin = nums.begin();
        auto end = std::upper_bound(nums.begin(), nums.end(), *begin);
        int pr = std::distance(begin, end);
        int prn = *begin;
        while (end != nums.end()) {
            begin = end;
            end = std::upper_bound(begin, nums.end(), *begin);
            int len = std::distance(begin, end);
            if (*begin - prn == 1)
                mx = std::max(len + pr, mx);
            pr = len;
            prn = *begin;
        }
        return mx;
    }
};