#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:

    bool check(int n) {
        while (n) {
            if (n % 10 == 0) return false;
            n /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        int b = n - 1;
        while (!(check(a) && check(b))) {
            a++;
            b--;
        }

        return {a, b};
    }
};