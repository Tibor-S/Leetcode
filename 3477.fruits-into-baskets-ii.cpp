#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        bool taken[100] {};
        int n = fruits.size();
        int c = n;
        for (int i = 0; i < n; i++) {
            int f = fruits[i];
            for (int j = 0; j < n; j++) {
                if (taken[j]) continue;
                if (f <= baskets[j]) {
                    taken[j] = true;
                    c--;
                    break;
                }
            }
        }

        return c;
    }
};