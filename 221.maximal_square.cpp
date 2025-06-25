#include <algorithm>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*
-   -   -   -   -   -   -   11  x   x   x
-   -   -   -   -   -   -   x   x   x   x
-   x   x   x   -   x   -   x   x   x   x
x   -   x   x   -   x   x   x   x   x   x
x   x   x   x   x   x   x   x   -   -   -
x   x   x   x   -   x   x   x   -   -   -  


up:     
left:   1   0   1   1   0

p=1
1   0   0   1   0


*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // {left, up}
        vector<short> m(matrix.front().size(), 0);

        short mx = 0;
        for (auto vec : matrix) {
            short p = m.front();
            if (vec.front() == '1') {
                m.front() = 1;
                if (mx == 0) mx = 1;
            } else {
                m.front() = 0;
            }
            
            for (int i = 1; i < vec.size(); i++) {
                short up = m[i];
                if (vec[i] == '1') {
                    m[i] = std::min({p, m[i-1], up}) + 1; // upleft = p, left = m[i-1], up = m[i]
                    mx = std::max(m[i], mx);
                } else {
                    m[i] = 0;
                }
                p = up;
            }
        }
        return mx * mx;
    }
};