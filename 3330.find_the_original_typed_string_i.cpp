#include <string>
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int possibleStringCount(string word) {
        int ci = 0;
        char curr = word[0];
        int ret = 1;
        for (int i = 1; i < word.length(); i++) {
            if (curr != word[i]) {
                ret += i - ci - 1;
                curr = word[i];
                ci = i;
            }
        }
        ret += word.length() - ci - 1;
        return ret;
    }
};