#include <algorithm>
#include <cstdint>
#include <functional>
#include <queue>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    struct event {
        bool operator()(const vector<int>& l, const vector<int>& r) const {
            if (l[0] == r[0]) return std::less<int>()(l[1], r[1]);
            return std::less<int>()(l[0], r[0]);
        }
        bool operator()(const vector<int>* l, const vector<int>* r) const {
            if (l->at(0) == r->at(0)) return l->at(1) > r->at(1);
            return l->at(0) > r->at(0);
        }
    };


    typedef std::priority_queue<vector<int>*, vector<vector<int>*>, event> Q;
    int maxEvents(vector<vector<int>>& events) {
        std::sort(events.begin(), events.end(), event());
        std::priority_queue<int, vector<int>, std::greater<int>> end_days {};
        int count = 0;

        auto first = events.begin();

        while (first != events.end()) {
            std::vector comp {first->at(0)+1, 0};
            auto end = std::lower_bound(first, events.end(), comp, event());
            auto it = first;
            while (it != end) {
                end_days.push(it->at(1));
                it++;
            }

            int free_room = end != events.end() ? end->at(0) - first->at(0) : INT32_MAX;
            int last_available = first->at(0);
            for (int i = 0; i < free_room && !end_days.empty(); end_days.pop()) {
                if (end_days.top() >= last_available) {count++; last_available++; i++;}
            }

            first = end;
        }

        return count;
    }
};