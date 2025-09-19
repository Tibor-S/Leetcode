#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        std::vector<int> ret {};
        int start = -1;
        int end = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) {
                int nstart = std::max(0, i - k);
                int nend = std::min((int)nums.size(), i + k + 1);
                if (start == -1) {
                    start = nstart;
                    end = nend;
                    continue;
                }

                if (nstart <= end) {
                    end = nend;
                } else {
                    for (int j = start; j < end; j++) {
                        ret.push_back(j);
                    }
                    start = nstart;
                    end = nend;
                }

            }
        }
        for (int j = start; j < end; j++) {
            ret.push_back(j);
        }
        return ret;
    }
};