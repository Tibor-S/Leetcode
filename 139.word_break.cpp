#include <set>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

l   e   e   t   c   o   d   e
0   1   2   3   4   5   6   7

a   p   p   l   e   p   e   n   a   p   p   l   e
0   1   2   3   4   5   6   7   8   9   10  11  12

3   5
8



*/

class Solution {
public:
    typedef std::set<int> Q;

    bool wordBreak(string s, vector<string>& wordDict) {
        Q start {0};

        while (!start.empty()) {
            int i = *start.begin();
            start.erase(i);
            for (auto &word : wordDict) {
                if (s.length() - i < word.length()) continue;
                bool match = true;
                for (int wi = 0; wi < word.length(); wi++) {
                    if (s[i+wi] != word[wi]) {match = false; break;}
                }
                if (match) {
                    int e = i + word.length();
                    if (e == s.length()) return true;
                    else if (e < s.length()) start.insert(e);
                }
            }
        }
 
        return false;
    }
};