#include <bitset>
#include <string>
using std::string;
using std::bitset;
/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */
/*

a   a   d   b   b   b   a   c   c   c                       
0   1   2   3   4   5   6   7   8   9

    a   a   b   c   c
d   ->  |  
b       ->  x-> v
b           v   v
c           ->  N
a
   
a   a   d   b   b   c   b   c   a   c

    a   a   b   c   c
d   ->  ->  V
b           x
b           V
c           V
a           ->  ->  

a   a   b   d   a   b   c   d

    a   a   b   d
a   0>  1v> 2>  3>  4v
b       1N          4v
d                   N
c


*/
// @lc code=start
#define VISITED(i1, i2) visited[200*(i1)+(i2)]
#define EQ1 (s1[i1] == s3[i3])
#define EQ2 (s2[i2] == s3[i3])
class Solution {
public:
    bitset<40401> visited {};
    string s1,s2,s3;
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length())
            return false;
        
        this->s1 = s1;this->s2 = s2;this->s3 = s3;
        return aux(0,0,0);
    }

    bool aux(int i1, int i2, int i3) {
        if (VISITED(i1, i2))
            return false;
        VISITED(i1, i2) = true;

        if (i1 == s1.length() && i2 == s2.length()) {
            return true;
        } else if (i1 == s1.length()) {
            if (EQ2) return aux(i1, i2+1, i3+1);
            else return false;
        } else if (i2 == s2.length()) {
            if (EQ1) return aux(i1+1, i2, i3+1);
            else return false;
        }

        if (EQ1 && EQ2) {
            if (aux(i1+1, i2, i3+1)) return true;
            else return aux(i1, i2+1, i3+1);
        } else if (EQ1) return aux(i1+1, i2, i3+1);
        else if (EQ2) return aux(i1, i2+1, i3+1);
        else return false;
    }
};
// @lc code=end

