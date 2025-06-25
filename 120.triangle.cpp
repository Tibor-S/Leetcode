#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) return triangle.front().front();
        int current = triangle.size()-2;
        int lower = triangle.size()-1;
        while (current >= 0) {
            auto& row = triangle[current--];
            auto& lrow = triangle[lower--];
            for (int i = 0; i < row.size(); i++) {
                row[i] += std::min(lrow[i], lrow[i+1]);
            }
        }

        return triangle.front().front();
    }
};