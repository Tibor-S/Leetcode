
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ret {};
        for (int st = 0; st < s.length(); st += k) {
            ret.push_back(s.substr(st, k));
        }
        while (ret.back().length() < k) {
            ret.back().push_back(fill);
        }
        return ret;
    }
};