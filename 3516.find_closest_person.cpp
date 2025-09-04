#include <cstdlib>
#include <string>
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int findClosest(int x, int y, int z) {
        return std::abs(z - x) < std::abs(z - y) ?
            1 :
            std::abs(z - x) == std::abs(z - y) ?
            0 :
            2;
    }
};