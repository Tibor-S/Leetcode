#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=2221 lang=cpp
 *
 * [2221] Find Triangular Sum of an Array
 */



/*

1
11
121
1331
14641;



1   1,1;1,2     1,1;2,2;1,3     1,1;3,2;3,3;1,4     1,1;4,2;6,3;4,4;1,5
2   1,2;1,3     1,2;2,3;1,4     1,2;3,3;3,4;1,5
3   1,3;1,4     1,3;2,4;1,5
4   1,4;1,5
5

r   n!/r!   D_desc  var
0   4!/0!   *1      r+1
1   4!/1!   *2
2   4!/2!   *3  
3   4!/3!   *4      
4   4!/4!   1

r   (n-r)!  D_desc  var
0   4!      *4      (n-r)
1   (4-1)!  *3
2   (4-2)!  *2      
3   (4-3)!  *1      
4   (4-4)!  1


*/
// @lc code=start
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for (int n = 0; n < nums.size(); n++) {
            for (int i = 0; i < nums.size() - n - 1; i++) {
                nums[i] = (nums[i] + nums[i+1]) % 10;
            }
        }
        return nums[0];
    }
};
// @lc code=end
// class Solution {
// public:
//     int triangularSum(vector<int>& nums) {
//         double n = nums.size() - 1;
//         double c = 1; // n!/r!
//         double y = 1; // (n-r)!
//         int tot = 0;
//         for (int i = 0; i < nums.size(); i++, c *= n-i+1, y *= i) { // r = n - i
//             int coef = (long) (c / y) % 10;
//             tot += (coef * nums[i]);
//         }
//         return tot % 10;
//     }
// };

