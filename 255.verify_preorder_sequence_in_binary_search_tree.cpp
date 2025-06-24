#include <cstdint>
#include <iterator>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*
0   1   2   3   4   5   6
0   1   2   2   1   2   2
5   2   1   3   7   6   8
h   l   x   x   x   x   x
    h   l   g   x   x   x
h               g   x   x
                h   l   g

x       1
xx      3
xxxx    7

0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15

h                                                           e
h   l                           g                           e
    h   l           g           eh  l           g           e
        h   l   g   eh  l   g   e   h   l   g   eh  l   g   e



0   1   2   3   4   5   6   7
                    re      
h                           e
h   l           g           e
    h   l   g   eh  l   g   e
*/

class Solution {
public:
    auto traverse(int min, int max, auto next, auto end) {
        if (next == end) return next;
        int val = *next;
        if (val < min || val > max) return next;
        next++;
        next = traverse(min, val, next, end);
        next = traverse(val, max, next, end);
        return next;
    }

    bool verifyPreorder(vector<int>& preorder) {
        auto it = preorder.begin();
        int val = *it;
        it++;
        it = traverse(-1, val, it, preorder.end());
        it = traverse(val, INT32_MAX, it, preorder.end());
        return it == preorder.end();
    }

};