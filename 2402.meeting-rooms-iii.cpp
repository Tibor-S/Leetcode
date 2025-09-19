#include <algorithm>
#include <functional>
#include <queue>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////




struct End {
    long long time;
    int room;
    End(int time, int room) : time(time), room(room) {}
    End(long long current, long long len, int room) : time(current + len), room(room) {}
}; 
template<>
struct std::greater<End> {
    constexpr bool operator()(const End& lhs, const End& rhs) const 
    {
        if (lhs.time == rhs.time) return lhs.room > rhs.room;
        return lhs.time > rhs.time;
    }
};

class Solution {
public:

    int mostBooked(int n, vector<vector<int>>& meetings) {
        std::priority_queue<End, vector<End>, std::greater<End>> next_end {};
        std::priority_queue<int, vector<int>, std::greater<int>> vacant {};

        std::sort(meetings.begin(), meetings.end(), [](auto&lhs, auto&rhs){
            if (lhs[0] == rhs[0]) return lhs[1] < rhs[1];
            return lhs[0] < rhs[0];
        });

        int visited[100] = {};
        for (int i = 0; i < n; i++) vacant.push(i);
        long long current = 0;
        for (int i = 0; i < meetings.size();) {
            int len = meetings[i][1] - meetings[i][0];
            visited[0]++;
            current = std::max((long long)meetings[i][0], current);
            next_end.emplace(current, len, vacant.top());
            vacant.pop();
            i++;
            while (!next_end.empty() && i < meetings.size()) {
                len = meetings[i][1] - meetings[i][0];
                current = std::max((long long)meetings[i][0], current);
                if (current < next_end.top().time) {
                    if (next_end.size() == n) { // at capacity
                        current = next_end.top().time;
                        int room = next_end.top().room;
                        next_end.pop();
                        visited[room]++;
                        next_end.emplace(current, len, room);
                    } else {
                        int room = vacant.top();
                        vacant.pop();
                        visited[room]++;
                        next_end.emplace(current, len, room);
                    }
                    i++;
                } else {
                    int room = next_end.top().room;
                    next_end.pop();
                    vacant.push(room);
                }
            }
        }

        int mxi = 0;
        for (int i = 0; i < n; i++) if (visited[i] > visited[mxi]) mxi = i;
        return mxi;
    }
};
