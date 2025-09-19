#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        auto first = nums.begin();
        auto last = std::upper_bound(first, nums.end(), *first, [](auto l,auto r){return l>r;});
        while (first != nums.end()) {
            if (std::distance(first, last) == 1) return *first;
            first = last;
            last = std::upper_bound(first, nums.end(), *first, [](auto l,auto r){return l>r;});
        }
        return -1;
    }
};