#include <algorithm>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int f = nums[0];
        int alternating = 1;
        int even = f & 1 ? 0 : 1;
        int odd = f & 1;
        int next = f & 1 ? 0 : 1;
        for (int i = 1; i < nums.size(); i++) {
            int n = nums[i];
            if (n & 1) {
                if (next) {
                    alternating++;
                    next = 0;
                }
                odd++;
            } else {
                if (!next) {
                    alternating++;
                    next = 1;
                }
                even++;
            }
        }
        
        return std::max({alternating, even, odd});
    }
};