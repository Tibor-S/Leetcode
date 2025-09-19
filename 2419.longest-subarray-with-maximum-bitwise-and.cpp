#include <algorithm>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

mx = 3
1   2   3   3   2   2
        li      ri    

*/



class Solution {
public:
    int mx = 0;
    int mxs = 0;
    int longestSubarray(vector<int>& nums) {
        for (auto n : nums) {
            mx = std::max(n, mx);
        }

        int li = -1;
        int ri = -1;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (n != mx) continue;

            li = i - 1;
            while (li > ri && (nums[li] & mx) == mx) li--;
            li++;
            ri = i + 1;
            while (ri < nums.size() && (nums[ri] & mx) == mx) ri++;
            i = ri;
            mxs = std::max(ri - li, mxs);
        }

        return mxs;
    }
};