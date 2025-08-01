#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret {};
        for (int i = 1; i <= numRows; i++)
            ret.emplace_back(i);
        ret[0][0] = 1;
        if (numRows == 1) return ret;
        ret[1][0] = 1;
        ret[1][1] = 1;
        for (int i = 2; i < numRows; i++) {
            int l = 0;
            int r = i;
            ret[i][l++] = 1;
            ret[i][r--] = 1;
            while (l <= r) {
                int val = ret[i-1][l] + ret[i-1][l-1];
                ret[i][l++] = val;
                ret[i][r--] = val;
            }
        }
        return ret;
    }
};