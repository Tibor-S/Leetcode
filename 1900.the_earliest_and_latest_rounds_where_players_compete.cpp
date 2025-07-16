#include <algorithm>
#include <array>
#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

p   m   s
1   1   7   1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
1   1   2   1, 2, 3, 4, 5, 6
1   0   0   1, 2, 4
*/
struct ea : std::array<char, 2> {
    ea(std::array<char, 2> arr) : std::array<char, 2>(arr) {}
    ea(char early, char late) : std::array<char, 2> {early, late} {}
    ea(ea& lhs, ea& rhs) : std::array<char, 2> {std::min(lhs[0], rhs[0]), std::max(lhs[1], rhs[1])} {}
};


bool player (uint32_t mask, char index) { return (mask >> index) & 1; }
uint32_t compose(char len, char p1index, char p2index) {
    uint32_t mask = ((uint32_t) len) << 28;
    mask |= (1 << p1index) | (1 << p2index);
    return mask;
}
bool match(uint32_t mask, char first_round_len = false) {
    char len = first_round_len ? first_round_len : mask >> 28;
    for (int i = 0; i < len / 2; i++) {
        if (player(mask, i)) {
            return player(mask, len - i - 1);
        }
    }
    return false;
}
uint32_t winners(uint32_t mask, int index, int first_round_len = 0) {
    int len = first_round_len ? first_round_len : mask >> 28;
    int nlen = len / 2 + (len & 1);
    int mid = -1;
    int free = len / 2 - 2;
    if (len & 1) {
        mid = (mask >> (len / 2)) & 1;
        if (mid) free++;
    }
    if (index >= 1 << std::max(free, 0)) return 0xFFFFFFFF;
    uint32_t nmask = (uint32_t) nlen << 28;
    
    char loff = 0;
    char roff = nlen - 1;
    for (int i = 0; i < len / 2; i++) {
        bool left = player(mask, i);
        bool right = player(mask, len - i - 1);
        
        if (left) {
            nmask |= 1 << loff++;
        } else if (right) {
            nmask |= 1 << roff--;
        } else {
            if (index & 1) loff++;
            else roff--;
            index>>=1;
        }
    }

    if (mid == 1) {
        nmask |= 1 << loff;
    }

    return nmask;
}

class Solution {
public:
    std::unordered_map<uint32_t, std::array<char, 2>> mem {
        {compose(2, 0, 1), ea(1, 1)},
        {compose(3, 0, 1), ea(2, 2)},
        {compose(3, 0, 2), ea(1, 1)},
        {compose(3, 1, 2), ea(2, 2)},
        {compose(4, 0, 1), ea(2, 2)},
        {compose(4, 0, 2), ea(2, 2)},
        {compose(4, 0, 3), ea(1, 1)},
        {compose(4, 1, 2), ea(1, 1)},
        {compose(4, 1, 3), ea(2, 2)},
        {compose(4, 2, 3), ea(2, 2)},
    };

    ea search(uint32_t mask) {
        if (mem.contains(mask)) return ea(mem.at(mask));

        if (match(mask)) {
            mem.insert({mask, ea(1,1)});
            return ea(1,1);
        }

        ea ret(16, 0);

        int i = 0;
        uint32_t w = winners(mask, i++);
        while (w != -1) {
            int len = w >> 28;
            ea e = search(w);
            ret = ea(e, ret);
            w = winners(mask, i++);
        }
        ret[0]++; ret[1]++;

        mem[mask] = ret;
        return ret;
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        uint32_t mask = compose(n, firstPlayer-1, secondPlayer-1);
        if (match(mask, n)) 
            return {1, 1};
        ea ret(15,0);
        int i = 0;
        uint32_t w = winners(mask, i++, n);
        while (w != -1) {
            int len = w >> 28;
            ea e = search(w);
            ret = ea(e, ret);
            w = winners(mask, i++, n);
        }
        ret[0]++; ret[1]++;

        return {ret[0], ret[1]};
    }
};