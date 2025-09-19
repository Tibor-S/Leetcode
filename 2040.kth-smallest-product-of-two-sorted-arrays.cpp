#include <algorithm>
#include <cstdint>
#include <iterator>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*
    2   4
-4  -8  -16
-2  -4  -8
0   0   0
3   6   12


i\j -3  -1  2   4   5
-2  6   2   -4  -8  -10
-1  3   1   -2  -4  -5
0   0   0   0   0   0
1   -3  -1  2   4   5
2   -6  -2  4   8   10  

k = 30
i\j -3  -2  -1  0   1   2   3  
-3  9   6   3   0   -3  -6  -9 
-2  6   4   2   0   -2  -4  -6
-1  3   2   1   0   -1  -2  -3  
0   0   0   0   0   0   0   0
1   -3  -2  -1  0   1   2   3
2   -6  -4  -2  0   2   4   6
3   -9  -6  -3  0   3   6   9

normal => lower_bound with cap
inverted => upper_bound with same cap and std::greater;


0   1   2   2   2   2   3   4   5   6
0   1   2   3   4   5   6   7   8   9
k = 4
L   H   klH count   step
0   7   10  7       3      
0   4   7   4       2
0   2   2   2       1
2   3   6   2       1
2   2   return 2;        

1   2   2   2   2   3   4   5   6
0   1   2   3   4   5   6   7   8
k = 5
L   H   klH mxl mxh step
1   6   8   5   6   2
1   4   6   3   4   1
1   3   5   2   3   1   


6   8   15  20

k=2
L=21
C   S   F   I   klI ge
19  9   6   15  2   


0     3 4  5  6     8  9     11 12 13 14 15 16  
5 5 5 9 10 11 12 12 15 16 16 17 20 22 23 28 30 30

k = 1
L = 31
C   S   F   I   klI ge
26  13  5   18  12  t
13  6   5   11  5   t
6   3   5   8   3   t
3   1   5   6   3   t
1   0   5   5   0   f
-1  0   6   

k = 10
L = 31
C   S   F   I   klI ge  mx  klX
26  13  5   18  12  t   17  11
13  6   5   11  5   f   -   -
6   3   12  15  8   f   -   -
2   1   16  17  11  t   16  9   ret 16
1   0   16  16  9   f   -   -
-1  0   17  



k = 29
i/j -9  -4  1   6   8   8   9   10
-10 90  40  -10 -60 -80 -80 -90 -100
-10 90  40  -10 -60 -80 -80 -90 -100
-8  72  36  -8  -48 -64 -64 -72 -80
-8  72  36  -8  -48 -64 -64 -72 -80
1   -9  -4  1   6   8   8   9   10
3   -27 -12 3   18  24  24  27  30
6   -54 -24 6   36  48  48  54  60
6   -54 -24 6   36  48  48  54  60
8   -72 -32 8   48  64  64  72  80
10  -90 -40 10  60  80  80  90  100
    5   4   0   4   4   4   4   4   = 29
         p
-25 ... -12 ... 0

i\j -10 -8  -7  -6
-8  80  64  56  48  
-6  60  48  42  36

-100 -90 -80 -80 -60  -10 40 90 
-100 -90 -80 -80 -60  -10 40 90 
-80  -72 -64 -64 -48  -8  36 72 
-80  -72 -64 -64 -48  -8  36 72 

-3  -2  -1
-6  -4  -2
-9  -6  -3      -6  -4  -2
b               b

*/
class Solution {
public:
    vector<int> *vert; 
    vector<int> *horz;

    long long mx;
    long long mn;
    long long found;

    long long at(int v, int h) { 
        if (v < 0) v = vert->size() + v;
        if (h < 0) h = horz->size() + h;
        return (long long)(*vert)[v] * (long long)(*horz)[h]; 
    }

    void set_mx_mn() {
        mx = std::max({
            at(0,0),
            at(0, -1),
            at(-1, 0),
            at(-1,-1)
        }) + 1;
        mn = std::min({
            at(0,0),
            at(0, -1),
            at(-1, 0),
            at(-1,-1)
        });
    }

    long long n_less(long long factor, long long cap) {
        if (factor == 0) {
            if (0 < cap) {
                found = std::max((long long)0, found);
                return horz->size();
            }
            return 0;
        }
        
        long long less;
        if (factor < 0) {
            auto first = std::upper_bound(
                horz->begin(),
                horz->end(), 
                cap, 
                [this, factor](long long cap, int&val) {
                    long long prod = factor * (long long) val;
                    return cap > prod;
                });
            less = std::distance(first, horz->end());
            if (first != horz->end()) found = std::max(factor*(long long)*first, found);
        } else {
            auto last = std::lower_bound(
                horz->begin(),
                horz->end(), 
                cap,
                [this, factor](int&val, long long cap){
                    long long prod = factor * (long long) val;
                    return prod < cap;
                });
            less = std::distance(horz->begin(), last);
            if (last != horz->begin()) found = std::max(factor*(long long)*(--last), found);
        }

        return less;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        if (nums1.size() <= nums2.size()) {
            vert = &nums1;
            horz = &nums2;
        } else {
            vert = &nums2;
            horz = &nums1;
        }


        set_mx_mn();
        mx++;
        long long count = mx - mn;
        while (count > 0) {
            found = INT64_MIN;
            long long step = count / 2;
            long long i = mn + step;

            long long k_less = 0;
            for (long long factor : *vert) {
                k_less += n_less(factor, i); 
            }

            if (k_less == k) return found;
            if (k_less > k) {
                count = step;
            } else {
                mn = ++i;
                count -= step+1;
            }
        }

        return mn - 1;
    }
};