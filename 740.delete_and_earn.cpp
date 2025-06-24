#include <algorithm>
#include <vector>
using std::vector;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

    count   sum
1   5       5
2   8       16
3   3       14
4   6       30
5   4       36
6   3       48



*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int curr = 0; int key = 0; 
        int _3 = 0; int key_3 = 0;
        int _2 = 0; int key_2 = 0;
        int _1 = 0; int key_1 = 0;
    
        auto it = nums.begin();
        while (it != nums.end()) {
            int c = *(it++);
            if (key == c) {
                curr += c;
            } else {
                curr += key_1 == key - 1 ? std::max(_3, _2) : std::max(_2, _1);
                _3 = _2;
                key_3 = key_2;
                _2 = _1;
                key_2 = key_1;
                _1 = curr;
                key_1 = key;
                curr = c;
                key = c;
            }
        }
        curr += key_1 == key - 1 ? std::max(_3, _2) : std::max(_2, _1);
        return std::max(_1, curr);
    }
};