#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        return std::distance(
            std::lower_bound(nums.begin(), nums.end(), target),
            std::upper_bound(nums.begin(), nums.end(), target)
        ) > nums.size() / 2;
    }
};