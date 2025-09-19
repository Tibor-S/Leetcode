#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

i\j 0   1
0   d   r
1   l   d

i\j 0   1   2
0   d       r
1       d   r
2   l   l   d

i\j 0   1   2   3
0   d           r
1       d   r   r
2       l   d   r
3   l   l   l   d

i\j 0   1   2   3   4
0   d               r
1       d       r   r
2           d   r   r
3       l   l   d   r
4   l   l   l   l   d

i\j 0   1   2   3   4   5
0   d                   r
1       d           r   r
2           d   r   r   r
3           l   d   r   r
4       l   l   l   d   r
5   l   l   l   l   l   d

*/

class Solution {
public:
    int n;
    int m;
    int mxh;

    int height(int i_j) {
        return std::min(i_j + 1, m - i_j);
        if (m & 1) {
            if (i_j <= m / 2) return i_j + 1;
            return m - i_j;
        } else {

        }
        if (i_j < n / 2) {

        }
        int h = i_j + 1;
        if (h > mxh) 
            return h - ((h - mxh) << 1);
        return h;
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        //top left child moves diagonally
        for (int i = 1; i < n; i++) 
            fruits[i][i] += fruits[i-1][i-1];

        // Build edges in range [0, n-1)
        m = n-1;
        mxh = n / 2; 

        for (int tj = 1; tj < m; tj++) {
            int th = height(tj);
            int tmi = n - th;
            int fj = tj - 1;
            int fh = height(fj);
            int fmi = n - fh;
            for (int ti = m; ti >= tmi; ti--) {
                int vals[3] = {0,0,0};
                for (int di = 0; di < 3; di++) {
                    int fi = ti + di - 1;
                    if (fi < fmi) continue;
                    if (fi > m) continue;
                    vals[di] = fruits[fi][fj];
                }
                fruits[ti][tj] += std::max({vals[0], vals[1], vals[2]});
            }
        }

        for (int ti = 1; ti < m; ti++) {
            int th = height(ti);
            int tmj = n - th;
            int fi = ti - 1;
            int fh = height(fi);
            int fmj = n - fh;
            for (int tj = m; tj >= tmj; tj--) {
                int vals[3] = {0,0,0};
                for (int dj = 0; dj < 3; dj++) {
                    int fj = tj + dj - 1;
                    if (fj < fmj) continue;
                    if (fj > m) continue;
                    vals[dj] = fruits[fi][fj];
                }
                fruits[ti][tj] += std::max({vals[0], vals[1], vals[2]});
            }
        }


        return fruits[m][m] + fruits[m-1][m] + fruits[m][m-1];
    }
};