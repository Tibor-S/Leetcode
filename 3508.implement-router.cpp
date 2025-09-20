
#include <algorithm>
#include <cstddef>
#include <deque>
#include <functional>
#include <iterator>
#include <unordered_set>
#include <vector>
using std::vector;
using std::deque;
using std::unordered_set;
using std::unordered_map;
/*
 * @lc app=leetcode id=3508 lang=cpp
 *
 * [3508] Implement Router
 */

// @lc code=start

struct packet {
    int source, destination, timestamp;
    packet(int a, int b, int c) : source(a), destination(b), timestamp(c) {}
};

template<>
struct std::equal_to<packet> {
    constexpr bool operator()(const packet &l, const packet &r) const {
        return l.source == r.source
            && l.destination == r.destination
            && l.timestamp == r.timestamp;
    }
};

template<>
struct std::hash<packet> {
    constexpr size_t operator()(const packet &p) const {
        size_t h1 = std::hash<int>{}(p.source);
        size_t h2 = std::hash<int>{}(p.destination);
        size_t h3 = std::hash<int>{}(p.timestamp);
        size_t h = h1 ^ (h2 << 1);
        h = h3 ^ (h << 1);
        return h;
    }
};


class Router {
public:
    unordered_set<packet> existing {};
    unordered_map<int, deque<int>> dest_to_tstamps {};
    deque<packet> queue {};
    int limit;

    Router(int memoryLimit) : limit(memoryLimit) {}
    
    bool addPacket(int source, int destination, int timestamp) {
        int s = existing.size();
        existing.emplace(source, destination, timestamp);
        if (s == existing.size()) 
            return false;
        queue.emplace_back(source, destination, timestamp);
        dest_to_tstamps[destination].push_back(timestamp);
        if (queue.size() > limit) {
            packet rem = queue.front();
            existing.erase(rem);
            queue.pop_front();
            dest_to_tstamps[rem.destination].pop_front();
        }
        return true;
    }
    
    vector<int> forwardPacket() {
        if (queue.empty()) 
            return {};
        packet ret = queue.front();
        existing.erase(ret);
        queue.pop_front();
        dest_to_tstamps[ret.destination].pop_front();
        return {ret.source, ret.destination, ret.timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int c = 0;
        deque<int> &tstamps = dest_to_tstamps[destination];
        auto first = std::lower_bound(tstamps.begin(), tstamps.end(), startTime);
        auto last = std::upper_bound(tstamps.begin(), tstamps.end(), endTime);
        return std::distance(first, last);
    }
};

// @lc code=end

