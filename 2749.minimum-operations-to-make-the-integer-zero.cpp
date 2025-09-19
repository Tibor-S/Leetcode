#include <string>
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

j: J, m = |J|
n1 - sum_j{2^j + n2} = 0
n1 - m*n2 - sum_j{2^j} = 0
n1 - m*n2 = sum_j{2^j}, 

condition:
as long as `exists m. [n1 - m*n2: NN]` there is a solution.
The solution is the number of positive bits in n1 - m*n2:NN

ex n1 = 3, n2 = -2
n1 - m*n2 = 3 + 2m
m   3 + 2m  bin
1   5       101
2   7       111
3   9       1001 = 0100 + 0101
4   11
5   13
6   14
7   15
8   

n       max_ops
0001    1    
0010    2
0100    4
1000    8

*/


class Solution {
public:

    long bit_count(long b) {
        long c = 0;
        while(b) {
            if (b & 1) c++;
            b>>=1;
        }
        return c;
    }

    int makeTheIntegerZero(int num1, int num2) {
        long m = 1;
        while(true) {
            long target = num1 - m * num2;
            if (target < 0) return -1;
            int bc = bit_count(target);
            if (bc <= m && m <= target) return m;
            m++;
        }
    }
};