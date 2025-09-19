#include <algorithm>
#include <functional>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int total = 0;

        std::sort(players.begin(), players.end(), std::greater<int>());
        std::sort(trainers.begin(), trainers.end(), std::greater<int>());

        int i = 0;
        int j = 0;
        for (; i < players.size() && j < trainers.size(); i++,j++) {
            while (i < players.size() && players[i] > trainers[j]) i++;
            if (i < players.size())
                total++;
        }

        return total;
    }
};