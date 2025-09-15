#include <sstream>
#include <string>
#include <unordered_set>
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        std::unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        std::stringstream stream(text);
        char delim = ' ';

        int ret = 0;
        string t;
        while (std::getline(stream, t, delim)) {
            ret++;
            for (char c : t) {
                if (broken.contains(c)) {ret--; break;}
            }
        }

        return ret;
    }
};