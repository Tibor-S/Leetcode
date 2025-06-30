#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////


/*

b   b  
b   a   b

b   b   b   a   b
0   1   2   3   4

i\j 0   1   2   3   4
0   1   2   3   3   4
1       1   2   2   3   
2           1   1   3  
3               1   1
4                   1

i\j 0   1   2   3   4
0   1   1   1   0   1
1       1   1   0   1
2           1   0   1
3               1   0
4                   1

g   t   k   k   o   p   h   e   c   p   h   h   x   w   f   o   
i   a   n   d   a   i   u   w   s   g   m   s   a   w   t   m

g   t   k   k   o   p   h   e   p   h   h   w   o   
m   t   w   a   s   m   g   s   w   i   a   a   i

g   t   k   k   o   p   h   e   p   h   h   w   o   i   a   a   i   w   s   g   m   s   a   w   t   m
0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25

g   t   k   k   o   p   h   e   p   h   h   w   o   i   a   a   i   w   s   g   m   s   a   w   t   m
0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25

i\j 0   1   2   3   4   5   6   7   8   9   
0   1   0   0   0   0   0   0   0   0   0
1       1   0   0   0   0   0   0   0   1
2           1   1   0   0   0   0   0   0
3               1   0   0   0   0   0   0
4                   1   0   0   0   0   0
5                       1   0   0   1   0
6                           1   0   0   0
7                               1   0   0
8                                   1   0
9                                       1

    0   1   2   3   4   5   6   7   8   9
    g   t   h   h   x   w   f   a   w   t
1   1   1   1   1   1   1   1   1   1   1
2   1   1   2   1   1   1   1   1   1   
3   1   2   2   1   1   1   1   1
4   2   2   2   1   1   3   1
5   2   2   2   1   3   3
6   2   2   2   3   3   
7   2   2   3   3
8   2   3   3   
9   3   5
10  5

g   0
t   1   9
h   2   3
x   4
w   5   8
f   6
a   7

g   t   h   h   x   w   f   a   w   t
0   1   2   3   4   5   6   7   8   9   end = 10e   
    1   2   3   4   5   6   7   8   9   end = 10e
        2   3   4   5   6   7   8   9   end = 10
            3   4   5   6   7   8   9   end = 4
        2,2     4   5   6   7   8   9   end = 10
                    5   6   7   8   9   end = 10
                        6   7   8   9   end = 9
                            7   8   9   end = 9
                                8   9   end = 9
                            1,2     9   end = 9
                        1,3         9   end = 9
                    3,4             9   end = 9


g   0
t   1   5   7
h   2   3   4   6

g   t   h   h   h   t   h   t       in  ou
0   1   2   3   4   5   6   7
0   0   0   0   0   0   0   0
    1   1   1   1   1   1   1
        2   2   2   2   2
            3   3   3   3
                4   4   4               
                    5   5   5       1   3
                        6           1   1   

    g   t   h   h   x   w   f   a   w   t
i\j 0   1   2   3   4   5   6   7   8   9   
0   1   1   1   2   2   2   2   2   3   5
1       1   1   2   2   2   2   2   3   5
2           1   2   2   2   2   2   3   3
3               1   1   1   1   1   3   3
4                   1   1   1   1   3   3
5                       1   1   1   3   3
6                           1   1   1   1
7                               1   1   1
8                                   1   1
9                                       1

    a   c   a   a   d   b   a   e   b   c
i\j 0   1   2   3   4   5   6   7   8   9   
0   0   0   X   0   0   0   X   0   0   0
1       0   0   0   0   0   0   0   0   X
2           0   X   0   0   0   0   0   0
3               0   0   0   0   0   0   0
4                   0   0   0   0   0   0   
5                       X   0   0   X   0   
6                           0   0   0   0   
7                               0   0   0   
8                                   0   0   
9                                       X   

L   0   1   2   3   4   5   6   7   8   9
1   1,5 1,9
2   2,2 
3   2,0 1,4 1,8
4   2,5 2,1
5   2,0 1,4 1,8
6   2,5 2,1
7   0
8   
9   1
10



L   0   1   2   3   4   5   6   7   8   9
1   5   9
2   2
3   0
4   5
5   
6
7   0
8   
9   1
10


0,9     0
    check 0,6

    check 9,8



*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.size() == 1) return 1;
        if (s.size() == 2) return s[0] == s[1] ? 2 : 1;
        vector<int> vec1(s.length(), 1);
        vector<int> vec2(s.length() - 1);
        for (int i= 0; i < vec2.size(); i++) {
            if (s[i] == s[i+1]) vec2[i] = 2;
            else vec2[i] = 1;
        }
        vector<int> vec3(s.length() - 2);

        int offset = 2;
        vector<int> *p2 = &vec1;
        vector<int> *p1 = &vec2;
        vector<int> *curr = &vec3;
        while (offset < s.length()) {
            for (int i = 0; i < s.length() - offset; i++) {

                int diag = p2->at(i+1) + (s[i] == s[i+offset] ? 2 : 0); 
                curr->at(i) = std::max({p1->at(i), p1->at(i+1), diag});
            }
            auto t = p2;
            p2 = p1;
            p1 = curr;
            curr = t;
            offset++;
        }

        return p1->at(0);
    }
};