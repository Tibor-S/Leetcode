#include <algorithm>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */
/*

mat:
1       0       1       0       0
1       0       1       1       1
1       1       1       1       1
1       0       0       1       0

process 0
1,1     0,0     1,1     0,0     0,0
process 1
1,2             1,2     2,1     3,1
process 2
1,3     2,1     1,2     2,1     3,1
                3,1     4,1     5,1
process 3
1,4     2,1     1,2     2,1     3,1
                3,1     4,1     5,1        
                        1,1
pop
1,4     2,1     1,2     2,2     3,1
                3,1     1,1     5,1            
pop
1,4     2,1     1,2     1,3     3,1
                3,1             5,1     
                        
0       0       1       0       1       0       0
0       1       1       1       1       1       0
0       0       1       1       1       0       0
0       1       1       1       1       1       0
0       0       1       0       1       0       0

stack 0:-------------------------------------------0
                1,1             1,1     
stack 1:-------------------------------------------0
        1,1     1,1     3,1     1,1     5,1
                2,1             4,1 
stack 2:-------------------------------------------5
                1,3     2,2     1,1
                                3,2 
stack 3:-------------------------------------------5
        1,1     1,3     2,2     1,1     5,1
                2,1     3,1     3,2 
                                4,1
stack 4:-------------------------------------------9
                1,5             1,5     
                                 
                                

*/
// @lc code=start
#define RECT(w,h) rect {w, h};
#define ACTIVE(x, y) (matrix[y][x] == '1')
#define EMPTY(x) (top[x]==-1)
#define TOP(x) (stack[top[x]][x])
#define PUSH(x, val) stack[++top[x]][x] = val
#define POP(x) (--top[x])
#define COLLAPSE(x) {\
    int h = 0;\
    while (!EMPTY(x)) {\
        TOP(x).h += h;\
        mx = std::max(TOP(x).area(), mx);\
        h = TOP(x).h;\
        POP(x);\
    }\
}
struct rect {
    int w, h;
    int area() {return w * h;}
};
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int mx = 0;
        int WIDTH = matrix[0].size(), HEIGHT = matrix.size();
        int top[200] = {};for(int i=0;i<WIDTH;i++)top[i]=-1; 
        rect stack[200][200] {};
        int pre = 0;
        if (ACTIVE(0, 0)) {
            PUSH(0, RECT(++pre, 1));
        }
        for (int x = 1; x < WIDTH; x++) {
            if (ACTIVE(x, 0)) {
                PUSH(x, RECT(++pre, 1))
            } else {
                pre = 0;
            }
        }

        for (int y = 1; y < HEIGHT; y++) {
            pre = 0;

            if (ACTIVE(0, y)) {
                if (!EMPTY(0)) {
                    TOP(0).h++;
                } else {
                    PUSH(0, RECT(1, 1))
                }
                pre++;
            } else {
                COLLAPSE(0);
            }

            for (int x = 1; x < WIDTH; x++) {
                if (ACTIVE(x, y)) {
                    int w = ++pre;
                    int h = 1;
                    while (!EMPTY(x)) {
                        rect prev = TOP(x);

                        if (prev.w < w) {
                            PUSH(x, RECT(w, h));
                            break;
                        } else if (prev.w == w) {
                            TOP(x).h += h;
                            break;
                        } else {
                            prev.h += h - 1;
                            mx = std::max(prev.area(), mx);
                            h = prev.h + 1;
                            POP(x);
                        }
                    }

                    if (EMPTY(x)) {
                        PUSH(x, RECT(w, h));
                    }
                } else {
                    COLLAPSE(x);
                    pre = 0;
                }
            }
        }

        for (int x = 0; x < WIDTH; x++) {
            COLLAPSE(x);
        }

        return mx;
    }
};
// @lc code=end

