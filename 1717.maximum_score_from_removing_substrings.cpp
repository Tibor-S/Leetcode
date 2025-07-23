#include <string>
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int expinc;
        int chpinc;
        char expc;
        char chpc;
        if (x > y) {
            expinc = x;
            chpinc = y;
            expc = 'a';
            chpc = 'b';
        } else {
            expinc = y;
            chpinc = x;
            expc = 'b';
            chpc = 'a';
        }

        int tot = 0;
        int expbefore = 0;
        int chpbefore = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == expc) {
                expbefore++;
            } else if (c == chpc) {
                if (expbefore > 0) 
                    {tot += expinc; expbefore--;}
                else
                    chpbefore++;
            } else {
                tot += std::min(chpbefore, expbefore) * chpinc;
                expbefore = 0;
                chpbefore = 0;
            }
        }
        tot += std::min(chpbefore, expbefore) * chpinc;

        return tot;
    }
};