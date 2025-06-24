#include <algorithm>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int ret = -1;
        vector<int> days(bulbs.size());
        for (int i = 0; i < days.size(); i++) {
            days[bulbs[i] - 1] = i + 1;
        }
        int eee = days.size() - k - 1;
        for (int i = 0; i < eee; i++) {
            int end = i + k + 1;
            int start_day = days[i];
            int end_day = days[end];
            int max_day = std::max(start_day, end_day);
            bool valid = true;
            for (int j = i+1; j < end; j++) {
                int day = days[j];
                if (day < max_day) {
                    valid = false;
                    break;
                }
            } 
            if (valid && (ret == -1 || max_day < ret)) ret = max_day;
        }
        return ret;
    }
};