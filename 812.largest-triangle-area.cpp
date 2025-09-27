#include <algorithm>
#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=812 lang=cpp
 *
 * [812] Largest Triangle Area
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>>* points;

    double area(int i, int j, int k) {
        int a[2] = {(*points)[i][0], (*points)[i][1]};
        int b[2] = {(*points)[j][0], (*points)[j][1]};
        int c[2] = {(*points)[k][0], (*points)[k][1]};
        double v[2] = {(double)(b[0] - a[0]), (double)(b[1] - a[1])};
        double w[2] = {(double)(c[0] - a[0]), (double)(c[1] - a[1])};

        return std::abs((v[0]*w[1] - v[1]*w[0]) / 2);
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        this->points = &points;
        double mxa = 0;
        for (int i = 0; i < points.size(); i++)
            for (int j = i+1; j < points.size(); j++)
                for (int k = j+1; k < points.size(); k++)
                    mxa = std::max(area(i,j,k), mxa);
        return mxa;
    }
};
// @lc code=end

