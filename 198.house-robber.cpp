#include <algorithm>
#include <vector>
using std::vector;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*


1   2   3   1
        4   
            3


2   7   9   3   1
        11
            10
                12
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return std::max(nums[0], nums[1]);
        nums[2] += nums[0];
        for (int i = 3; i < nums.size(); i++) {
            nums[i] += std::max(nums[i-2], nums[i-3]);
        }

        int i = nums.size();
        return std::max(nums[--i], nums[--i]);
    }
};