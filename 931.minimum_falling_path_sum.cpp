#include <algorithm>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if (matrix.size() == 1) return matrix.front().front();
        for (int i = 1; i < matrix.size() - 1; i++) {
            auto& upper = matrix[i-1];
            auto& row = matrix[i];
            row[0] += std::min(upper[0], upper[1]);
            row.back() += std::min(upper[upper.size()-2], upper.back());
            for (int j = 1; j < row.size() - 1; j++) {
                row[j] += std::min({upper[j-1], upper[j], upper[j+1]});
            }
        }

        auto& upper = matrix[matrix.size()-2];
        auto& row = matrix.back();
        int mn = std::min(
            row.front() + std::min(upper.front(), upper[1]),
            row.back() + std::min(upper.back(), upper[upper.size() - 2])
        );
        for (int j = 1; j < row.size() - 1; j++) {
            mn = std::min(mn, row[j] + std::min({upper[j-1], upper[j], upper[j+1]}));
        }
        return mn;
    }
};