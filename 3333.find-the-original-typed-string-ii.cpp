#include <iterator>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

j   0   1   2   3   4   5   6   7   8   9   10
j   0   1   2   3   4   5   6   7   8   9   10

Less than k!            A   B   C   D   E   F   G   sum
0 <= A,B,C,D,E,F,G  =   5   3   4   6   7   2   3   30
if k <= 7 return 0

T = i + j   forall i in [A,G]. forall j in [0,i] 

T: extra space; 

initial nothing added
T   0   1   2   3   4   5   6   7   8   9   10
=T  1   0   0   0   0   0   0   0   0   0   0
<T  0   1   1   1   1   1   1   1   1   1   1

i = A   
T   0   1   2   3   4   5   6   7   8   9   10
=T  1   1   1   1   1   1   0   0   0   0   0
<T  0   1   2   3   4   5   6   6   6   6   6

a produces the strings "","a","aa","aaa","aaaa","aaaaa"
=T for i = B will be the number of previous strings that can
be turned into T by appending "","b","bb" or "bbb"
this will always be a range in <T of size <=B

i = B
T   0   1   2   3   4   5   6   7   8   9   10
=T  1   2   3   3   3   3   2   1   0   0   0  
<T  0   1   3   6   9   12  15  17  18  18  18


1   2   3
0   0   0
0   0   1
0   0   2
0   1   

2   3   3   2 =>    1   2   2   1   =>  total = 36
k = 7
T_l = 7 - 4 = 3


T   0   1   2
=T  1   0   0  
<=T 1   1   1

1:                      "" and "a"
T   0   1   2
=T  1   1   0   if range is ob take (<=T)[i] - 0
<=T 1   2   2

2:
T   0   1   2
=T  1   2   2
<=T 1   3   5

2:
T   0   1   2
=T  1   3   5
<=T 1   4   9

1:
T   0   1   2
=T  1   4   8
<=T 1   5   13

/ no eq

T   0   1   2   3   4
<=T 1   1   1   1   1

1:                      "" and "a"
T   0   1   2   3   4
<=T 1   2   2   2   2

2:
T   0   1   2   3   4
<=T 1   3   5   6   6

2:
T   0   1   2   3   4
<=T 1   4   9   14  17

1:
T   0   1   2   3   4
<=T 1   5   13  23  31


2   2   2   2
T   0   1   2
<=T 1   1   1

1:
T   0   1   2   3
=T  1   1   0   0
<=T 1   2   2   2
1:
T   0   1   2
<=T 1   3   4
1:
T   0   1   2
<=T 1   3   3

*/
class Solution {
public:
    int possibleStringCount(string word, int k) {
        long long total = 1;
        std::vector<int> groups = {};
        auto begin = word.begin();
        do {
            auto end = begin;
            while (end != word.end() && *end == *begin) end++;
            int dist = std::distance(begin, end);
            total = (total * dist) % 1000000007;
            groups.push_back(dist);
            begin = end;
        } while (begin != word.end());

        if (k <= groups.size()) return total;
        int t_lim = k - groups.size();
        
        int t_leq[2000];
        for (auto& n : t_leq) n = 1;
        // Initialized as:
        // eq_t = {1,0,0,...} => leq_t = {0,1,1,1,1,...}

        for (int group_size : groups) {
            // eq_t
            for (int t = t_lim - 1; t >= 0; t--) { // number of ways to create t
                long long prefix_r = t_leq[t];
                long long prefix_l = t > group_size ? t_leq[t - group_size] : t == group_size ? 1 : 0;
                long long t_eq = prefix_r - prefix_l;
                t_leq[t] = t_eq >= 0 ? t_eq : t_eq + 1000000007;
            }
            // prefix
            for (int t = 1; t < t_lim; t++) t_leq[t] = (t_leq[t] + t_leq[t-1]) % 1000000007;
        }

        int ret = total - t_leq[t_lim - 1];

        return ret >= 0 ? ret : ret + 1000000007;
    }
};



