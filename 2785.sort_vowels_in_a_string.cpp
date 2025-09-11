#include <algorithm>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:

    bool vowels[58] = {};
    void init() {
        vowels[65 - 65] = true;
        vowels[69 - 65] = true;
        vowels[73 - 65] = true;
        vowels[79 - 65] = true;
        vowels[85 - 65] = true;
        vowels[97 - 65] = true;
        vowels[101 - 65] = true;
        vowels[105 - 65] = true;
        vowels[111 - 65] = true;
        vowels[117 - 65] = true;
    }

    string sortVowels(string s) {
        init();
        std::vector<int> next {};
        std::vector<int> indices {};
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (vowels[c - 65]) {
                indices.push_back(i);
                next.push_back(c);
            }
        }
        std::sort(next.begin(), next.end());
        int ci = 0;
        for (int i:indices) {
            s[i] = next[ci++];
        }

        return s;
    }
};