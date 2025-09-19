#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <unordered_set>
#include <vector>

/*
lim = 4
8   2   4   7
1   1   1   1
_   2   2   
_   3 

i\j 0   1   2   3
0   0   6   4   1
1       0   2   5
2           0   3
3               0

0   1   2   3   4   5
10  1   2   4   7   2

i\j 0   1   2   3   4   5
0   0   9   8   6   3   8
1       0   1   3   6   1
2           0   2   5   0
3               0   3   2
4                   0   5
5                       0


*/  

using std::vector;

struct SubArray {
    std::queue<int> arr;
    std::multiset<int> all;
    int d;

    SubArray() : arr(), all(), d(0) {
    } 
    SubArray(int init) : arr({init}), all({init}), d(0) {
    } 

    // int diff(int val) {
    //     auto last = all.end();
    //     last--;
    //     int mn = std::min(*(all.begin()), val);
    //     int mx = std::max(*(last), val);
    //     return mx - mn;
    // }

    int diff() {
        return d;
    }

    void push(int val) {
        arr.push(val);
        all.insert(val);
        d = max() - min();
    }

    int min() {
        return *(all.begin());
    }

    int max() {
        auto last = all.end();
        last--;
        return *(last);
    }

    void pop() {
        int val = arr.front();
        arr.pop();
        all.extract(val);
        d = max() - min();
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int longest = 0;

        SubArray window {};
        for (int i = 0; i < nums.size(); i++) {
            int left = nums.size() - i;
            if (left < longest - window.arr.size()) break;
            
            int num = nums[i];
            window.push(num);
            while(window.diff() > limit) window.pop();
            if (window.arr.size() > longest) longest = window.arr.size();
        }

        return longest;
    }
};