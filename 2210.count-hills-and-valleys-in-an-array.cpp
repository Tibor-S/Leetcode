#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int tot = 0;

        int i = 0;
        while (i < nums.size() - 1 && nums[i] == nums[i+1]) i++;
        if (i == nums.size() - 1) return 0;

        int slope;
        if (nums[i] < nums[++i]) {
            slope = 1;
        } else {
            slope = -1;
        }

        for(; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i+1]) {
                if (slope != 1) tot++;
                slope = 1;
            } else if (nums[i] > nums[i+1]){
                if (slope != -1) tot++;
                slope = -1;
            }
        }

        return tot;
    }
};