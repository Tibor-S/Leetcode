#include <algorithm>
#include <array>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////


/*

a   b   c   d   e   f   g

arr
a
    ab
b       abc
    bc      abcd
c       bcd     abcde
    cd      bcde    abcdef
d       cde     bcdef   abcdefg       
    de      cdef    bcdefg
e       def     bcdefg
    ef      defg
f       efg
    fg
g   

b   1   2   4
0   0   -   -
1   1   1   -
2   2   2   2


b   4   2   1   2   4
0   2   2   2   -   -
1   1   1   3   3   -
2   0   4   4   4   4
*/

class Solution {
public:
    std::unordered_set<int> mem;
    int subarrayBitwiseORs(vector<int>& arr) {
        std::array<vector<int>, 32> occurences {};

        for (int i = 0; i < arr.size(); i++) {
            int n = arr[i];
            if (!n) mem.insert(0);
            for (int bi = 0; bi < 32; bi++) {
                if (n & (1 << bi)) occurences[bi].push_back(i);
            }
        } 

        std::map<int, int> possible {}; // possible[index] = or
        for (int i = 0; i < arr.size(); i++) {
            possible.clear();
            for (int bi = 0; bi < 32; bi++) {
                auto it = std::lower_bound(occurences[bi].begin(), occurences[bi].end(), i);
                if (it == occurences[bi].end()) continue;
                int first_occ = *it;
                possible[first_occ] |= 1 << bi;
            }

            int tot = 0;
            for (auto &[at, val] : possible) {
                tot |= val;
                mem.insert(tot);
            }
        }

        return mem.size();
    }
};