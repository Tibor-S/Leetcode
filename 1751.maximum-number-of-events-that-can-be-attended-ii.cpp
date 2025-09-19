#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    vector<vector<int>>* events;
    typedef decltype(events->begin()) I;
    
    vector<std::pair<int, int>> mem;

    int search(int i, int end, int k) {
        if (k == 0 || i == end) return 0;
        if (mem[i].second == k) return mem[i].first;


        // Choose current;
        int jump_start = (*events)[i][1]+1;
        auto current = events->begin();
        std::advance(current, i);
        I jump = std::lower_bound(current, events->end(), jump_start, [](auto &it, auto val){
            return it[0] < val;
        });
        int ji = std::distance(events->begin(), jump);
        int choose_max = (*current)[2] + search(ji, end, k-1);

        // Ignore current;
        int ignore_max = search(i+1, end, k);

        int mx = std::max(choose_max, ignore_max);

        mem[i].first = mx;
        mem[i].second = k;

        return mx;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        std::sort(events.begin(), events.end(), [](auto& l, auto& r){
            if (l[0] == r[0]) return l[1] < r[1];
            return l[0] < r[0];
        });

        this->events = &events;
        mem = std::vector<std::pair<int, int>>(events.size(), {-1, -1});

        return search(0, events.size(), k);
    }
};