#include <algorithm>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////



/*

f   1   2   3   2   2
1   1,1 2,2 3,3 2,2 2,2
2       1,2 2,3 2,3 2,2
3   x           2,3 2,3
4   x               2,3


(pw * iw) + (pw + iw) * s1

s\pi00  01  11  10
0           1   
1       1   1   1

sp'i ^ spi   

*/


class Solution {
public:
    struct B {
        int lst;
        int other;
        int tot_len;
        int lst_len;
        B(int f) : lst(f), other(-1), tot_len(1), lst_len(1) {}
        bool single() { return other == -1; }
        void append(int n) {
            if (n == lst) {
                tot_len++;
                lst_len++;
            } else if (other == n) {
                int t = lst;
                lst = other;
                other = t;
                lst_len = 1;
                tot_len++;
            } else if (single()) {
                other = lst;
                lst = n;
                lst_len = 1;
                tot_len++;
            } else {
                other = lst;
                lst = n;
                tot_len = lst_len + 1;
                lst_len = 1;
            }
        }
    };

    int totalFruit(vector<int>& fruits) {
        B b (fruits[0]);
        int mx = 1;
        for (int i = 1; i < fruits.size(); i++) {
            b.append(fruits[i]);
            mx = std::max(b.tot_len, mx);
        }
        return mx;
    }
};