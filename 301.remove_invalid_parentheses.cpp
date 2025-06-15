
#include <optional>
#include <string>
#include <unordered_set>
#include <vector>

/*
0   1   2   3   4   5   6
(   )   (   )   )   (   )

i\j 0   1   2   3   4   5   6
0   F   T   F   T   F   F   F
1       F   F   F   F   F   F
2           F   T   F   F   T
3               F   F   F   F
4                   F   F   F
5                       F   T
6                           F

0   1   2   3   4   5   6   7
(   a   )   (   )   )   (   )
   
i\j 0   1   2   3   4   5   6   7
0   F   F   T   F   T   F   F   F
1       T   F   F   F   F   F   F
2           F   F   F   F   F   F
3               F   T   F   F   F
4                   F   F   F   F
5                       F   F   F
6                           F   T
7                               F
*/

using std::vector;
using std::string;

std::optional<int> invalid(string s) {
    int layer = 0;
    int after_last_zero = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        switch (c) {
            case '(': layer++; break;
            case ')': layer--; break;
        }
        if (layer < 0) return i;
        if (layer == 0) after_last_zero = i + 1;
    }

    if (layer != 0) {
        return after_last_zero - s.size();
        bool found_left = false;
        for (int i = 1; i <= s.size(); i++) {
            if (!found_left) {
                found_left = s[s.size() - i] == '(';
                continue;
            }

            if (s[s.size() - i] == '(') continue;

            return -i + 1;
        }
        if (found_left) return -s.size();

    }
    return {};
} 

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        std::unordered_set<string> conts {};
        std::unordered_set<string> new_conts {s};
        bool finished = false;
        while (!finished) {
            conts = new_conts;
            new_conts.clear();

            for (auto cont : conts) {
                std::optional<int> pos_opt = invalid(cont);
                if (!pos_opt.has_value()) {
                    finished = true;
                    break;
                }

                int pos = pos_opt.value();
                
                // (
                if (pos < 0) {
                    for (int i = cont.size() + pos; i < cont.size(); i++) {
                        if (cont[i] == '(') {
                            string new_s = cont;
                            new_s.erase(i, 1);
                            new_conts.insert(new_s);
                        }
                    }
                    continue;
                    int i = cont.size() + pos;
                    while (i < cont.size() && cont[i] == '(') {
                        string new_s = cont;
                        new_s.erase(i, 1);
                        new_conts.insert(new_s);
                        i++;
                    }
                    continue;
                }

                // )
                for (int i = 0; i <= pos; i++) {
                    if (cont[i] == ')') {
                        string new_s = cont;
                        new_s.erase(i, 1);
                        new_conts.insert(new_s);
                    }
                }
            }
        }

        vector<string> ret {};
        for (auto cont : conts) {
            std::optional<int> pos_opt = invalid(cont);
            if (!pos_opt.has_value()) 
                ret.push_back(cont);
        }
        return ret;
    }
};