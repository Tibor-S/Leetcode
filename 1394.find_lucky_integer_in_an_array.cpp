#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    int findLucky(vector<int>& arr) {
        std::sort(arr.begin(), arr.end(), std::greater<int>());

        auto begin = arr.begin();
        do {
            auto end = std::upper_bound(begin, arr.end(), *begin, std::greater<int>());
            if (std::distance(begin, end) == *begin) {
                return *begin;
            }
            begin = end;
        } while (begin != arr.end());
        
        return -1;
    }
};