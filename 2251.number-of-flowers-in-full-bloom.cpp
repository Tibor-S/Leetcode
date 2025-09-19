#include <queue>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

struct Person {
    int i;
    int fi;

    bool operator()(Person& lhs, Person& rhs) const {
        return lhs.fi > rhs.fi;
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> next_start {};
        std::priority_queue<int, std::vector<int>, std::greater<int>> next_end {};
        std::priority_queue<Person, std::vector<Person>, Person> imp {};
        int largest = 0;
        for (int i = 0; i < people.size(); i++) {
            int fi = people[i];
            if (fi > largest) largest = fi;
            imp.push({.i = i, .fi = fi});
        }
        for (auto& flower : flowers) {
            int fs = flower[0];
            int fe = flower[1];
            if (fs <= largest) next_start.push(fs);
            if (fe < largest) next_end.push(fe);
        }

        int x = 0;
        while (!imp.empty()) {
            int fi = imp.top().fi;
            int i = imp.top().i;
            while (!next_start.empty() && next_start.top() <= fi) {
                x++;
                next_start.pop();
            }
            while (!next_end.empty() && next_end.top() < fi) {
                x--;
                next_end.pop();
            }
            people[i] = x;
            imp.pop();
        }        

        return people;
    }
};