#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret(n);
        for (int i = 1; i < n; i++) ret[i] = i;
        ret[0] = -(n-1) * n / 2;
        return ret;
    }
};