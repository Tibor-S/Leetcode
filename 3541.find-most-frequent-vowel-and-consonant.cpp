#include <algorithm>
#include <string>
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:

    static const int L = 123 - 97;
    bool vowels[L] = {};

    int maxFreqSum(string s) {
        vowels['a' - 97] = vowels['e' - 97] 
            = vowels['i' - 97] 
            = vowels['o' - 97] 
            = vowels['u' - 97] 
            = true;
        int freq[L] = {};
        for (char c : s) freq[c-97]++;

        int mxv = 0, mxc = 0;
        for (char c : s) {
            if (vowels[c - 97])
                mxv = std::max(freq[c - 97], mxv);
            else
                mxc = std::max(freq[c - 97], mxc);
        }

        return mxv + mxc;
    }
};