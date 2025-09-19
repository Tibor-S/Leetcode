#include <set>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        std::multiset<int> indices {};
        for (int i = 0; i < k; i++) indices.insert(nums[i]);
        for (int i = k; i < nums.size(); i++) {
            indices.insert(nums[i]);
            indices.extract(*indices.begin());    
        }

        vector<int> ret {};
        for (auto &n : nums) {
            if (indices.contains(n)) {
                ret.push_back(n);
                indices.extract(n);
            }
        }

        return ret;
    }
        
};