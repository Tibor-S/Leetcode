#include <algorithm>
#include <cstdint>
#include <string>
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////


/*

i   n   t   e   n   t   i   o   n
e   x   e   c   u   t   i   o   n
^
|   insert is worse than replace
|   replace could work
|   delete


if same size use replace
otherwise branch delete and insert

*/


class Solution {
public:
    int meml1s2[501][501] = {};
    int meml2s1[501][501] = {};

    int mem(int li, int si, bool l1s2) {
        return l1s2 ? meml1s2[li][si] : meml2s1[li][si];
    }
    void set(int li, int si, bool l1s2, int val) {
        l1s2 ? meml1s2[li][si] = val : meml2s1[li][si] = val;
    }

    int branch(string &lword, string& sword, int li, int si, bool l1s2) {
        int mm = mem(li, si, l1s2);
        if (mm != -1) return mm;
        if (si == sword.length()) {
            set(li, si, l1s2, lword.length() - li);
            return lword.length() - li;
        } // insert until full
        // insert
        int icost;
        int nli = li + 1;
        if (lword.length() - nli < sword.length() - si) {
            icost = 1 + branch(sword, lword, si, nli, !l1s2);
        } else {
            icost = 1 + branch(lword, sword, nli, si, l1s2);
        }

        // delete
        int dcost = 1 + branch(lword, sword, li, si+1, l1s2);

        // replace
        int rcost = 1 + branch(lword, sword, li+1, si+1, l1s2);

        // do nothing
        int ncost = lword[li] == sword[si] 
            ? branch(lword, sword, li+1, si+1, l1s2)
            : INT32_MAX; 

        // return
        set(li, si, l1s2, std::min({icost, dcost, rcost, ncost}));
        return std::min({icost, dcost, rcost, ncost});
    }

    int minDistance(string word1, string word2) {
        if (word1.empty()) return word2.length();
        if (word2.empty()) return word1.length();
        for (int i = 0; i < 501; i++) for (int j = 0; j < 501; j++) meml1s2[i][j] = meml2s1[i][j] = -1;
        bool l1s2 = true;
        string &lword = word1;
        string &sword = word2;
        if (lword.length() < sword.length()) {
            l1s2 = false;
            string t = word1;
            lword = word2;
            sword = t;
        }
        return branch(lword, sword, 0, 0, l1s2);
    }
};