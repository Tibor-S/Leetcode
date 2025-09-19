#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:

    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);

        for (int bi = 0; bi < 32; bi++) {
            int tst = (1 << bi);
            int nxt_1 = -1;
            for (int i = 0; i < nums.size(); i++) {
                if (i <= nxt_1) {
                    ret[i] = std::max(nxt_1 - i + 1, ret[i]);
                    continue;
                } 
                nxt_1 = i;
                for (; nxt_1 < nums.size(); nxt_1++) {
                    if (nums[nxt_1] & tst) break;
                }
                if (nxt_1 == nums.size()) break;
                ret[i] = std::max(nxt_1 - i + 1, ret[i]);
            }
        }

        return ret;
    }
};