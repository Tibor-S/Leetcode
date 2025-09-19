#include <string>
#include <unordered_map>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

i/j 0   1   2   3
0   a   b   c   d
1   b   e   f   g
2   c   f   h   i
3   d   g   i   j

*/


class Solution {
public:    
    std::unordered_map<string, std::vector<string>> exists {};
    std::vector<std::vector<string>> ret {};

    void expand(vector<string> sq) {
        if (sq[0].length() == sq.size()) {
            ret.push_back(sq);
            return;
        }

        string prefix = "";
        int take = sq.size();
        for (auto &w : sq) {
            prefix.append(1, w[take]);
        }

        for (auto &w : exists[prefix]) {
            std::vector<string> nsq(sq.begin(), sq.end());
            nsq.push_back(w);
            expand(nsq);
        }
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        for (auto &w : words) {
            for (int i = 0; i < w.length(); i++) {
               exists[w.substr(0,i+1)].push_back(w);
            }
        }
        for (auto &w : words) {
            expand({w});
        }
        return ret;
    }
};