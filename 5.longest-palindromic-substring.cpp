#include <string>
#include <vector>
using std::string;

/*
babad
mat
i\j 0   1   2   3   4   
0   1   -   2   -   -
1       3   -   2   - 
2           3   -   -
3               1   -
4                   1
           
cbbd
mat
i\j 0   1   2   3
0   1   -   -   -
1       1   2   -
2           1   -
3               1
            

*/

template<typename T>
struct Matrix {
    int width;
    std::vector<T> vec;

    Matrix(int width, int height) : width(width), vec(width * height) {}

    T get(int row, int col) { return vec[row * width + col]; }
    void set(int row, int col, T val) { vec[row * width + col] = val; }
};

class Solution {
public:
    string longestPalindrome(string s) {
        string palindrome = "";
        Matrix<int> same_mat(s.size(), s.size());
        int last = s.size() - 1;
        for (int dist = last; dist >= 0; dist--) {
            if (s[0] == s[dist])
                same_mat.set(0, dist, dist + 1);
            else
                same_mat.set(0, dist, -1);

            if (s[last] == s[last - dist])
                same_mat.set(last - dist, last, dist + 1);
            else
                same_mat.set(last - dist, last, -1);

            for (int i = 1; i + dist < last; i++) {
                if (s[i] == s[i + dist]){
                    int val = same_mat.get(i - 1, i+dist+1);
                    if (val != -1)
                        same_mat.set(i, i+dist, val);
                    else
                        same_mat.set(i, i+dist, dist + 1);
                } else {
                    same_mat.set(i, i+dist, -1);
                }
            }
        }

        bool even = false;
        int maxi = 0;
        int maxl = 1;

        for (int i = 0; i < s.size() - 1; i++) {
            int d = same_mat.get(i, i + 1);
            if (d > maxl) {
                even = true;
                maxi = i;
                maxl = d; 
            }
        }

        for (int i = 0; i < s.size(); i++) {
            int d = same_mat.get(i, i);
            if (d > maxl) {
                even = false;
                maxi = i;
                maxl = d; 
            }
        }

        int start;
        if (even) 
            start = maxi - maxl / 2 + 1;
        else
            start = maxi - maxl / 2;

        return s.substr(start, maxl);
    }
};