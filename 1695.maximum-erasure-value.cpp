#include <string>
#include <unordered_map>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        std::unordered_map<int, bool> in_range {};
        int mx = 0;
        int s = 0;
        int b = 0;
        int e = 0;
        while (e < nums.size()) {
            int val = nums[e++];
            while (in_range[val]) {
                int val = nums[b++];
                in_range[val] = false;
                s -= val;
            }
            s += val;
            mx = std::max(s, mx);
            in_range[val] = true;
        }
        mx = std::max(s, mx);

        return mx;
    }
};