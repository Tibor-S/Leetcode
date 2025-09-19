#include <algorithm>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> &gap_start = endTime;
        vector<int> &gap_end = startTime;

        gap_start.insert(gap_start.begin(),0);
        gap_end.push_back(eventTime);
        int biggest = 0;
        int biggest_1 = 0;
        int biggest_2 = 0;

        for (int i = 0; i < gap_start.size(); i++) {
            int start = gap_start[i];
            int end = gap_end[i];
            int size = end - start;
            if (size > biggest) {
                biggest_2 = biggest_1;
                biggest_1 = biggest;
                biggest = size;
            } else if (size > biggest_1) {
                biggest_2 = biggest_1;
                biggest_1 = size;
            } else {
                biggest_2 = std::max(size, biggest_2);
            }
        }


        int mxs = 0;
        for (int i = 0; i < gap_start.size() - 1; i++) {
            int lstart = gap_start[i]; int lend = gap_end[i]; int lsize = lend - lstart; 
            int rstart = gap_start[i + 1]; int rend = gap_end[i + 1]; int rsize = rend - rstart;
            int ev_len = rstart - lend;

            int nsize;
            if (ev_len <= biggest_2) nsize = lsize + ev_len + rsize;
            else if (ev_len <= biggest_1) {
                if ((biggest_1 == lsize && biggest == rsize) ||
                    (biggest_1 == rsize && biggest == lsize))
                {
                    nsize = lsize + rsize;
                } else {
                    nsize = lsize + ev_len + rsize;
                }
            } else if (ev_len <= biggest) {
                if (biggest == lsize || biggest == rsize)
                    nsize = lsize + rsize;
                else
                    nsize = lsize + ev_len + rsize;
            } else {
                nsize = lsize + rsize;
            }
            mxs = std::max(nsize, mxs);
        }

        return mxs;
    }
};