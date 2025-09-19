#include <algorithm>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        auto &empty_start = endTime;
        auto &empty_end = startTime;

        empty_start.insert(empty_start.begin(), 0);
        empty_end.push_back(eventTime);

        // auto &empty_size = empty_start;
        int s = 0;
        for (int i = 0; i < k+1; i++) s += empty_end[i] - empty_start[i];
        int mxs = s;
        for (int i = k+1; i < empty_start.size(); i++) {
            s += empty_end[i] - empty_start[i];
            int j = i - (k+1);
            s -= empty_end[j] - empty_start[j];
            mxs = std::max(s, mxs);
        }

        return mxs;
    }
};