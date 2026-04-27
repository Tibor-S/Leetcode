#include <bitset>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::bitset;
/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
#define D(c1) ((c1) - '0')
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret {};
        int len = s.length();
        if (12 < s.length() || s.length() < 4)
            return {};

        bitset<4> valid[20] {};
        int i = 0; 
        for (; i < s.length() - 1; i++) {
            int val = D(s[i]);
            valid[i][1] = true;
            if (!val)
                continue;

            val = 10 * val + D(s[i+1]);
            valid[i][2] = true;

            val = 10 * val + D(s[i+2]);
            if (val < 256)
                valid[i][3] = true;
        }

        valid[i][1] = true;
        if (D(s[i])) {
            valid[i][2] = true;
        }
        valid[++i][1] = true;

        int ml1 = std::max(1, len - 9);
        for (int l1 = ml1; l1 <= 3; l1++) {

            if (!valid[0][l1])
                continue;
            
            int l234 = len - l1;
            int ml2 = std::max(1, l234 - 6);
            for (int l2 = ml2; l2 <= 3; l2++) {
                
                if (!valid[l1][l2])
                    continue;    
                
                int l12 = l1 + l2;
                int l34 = l234 - l2;
                int ml3 = std::max(1, l34 - 3);
                for (int l3 = ml3; l3 <= 3; l3++) {
                    int l123 = l12 + l3;
                    int l4 = l34 - l3;

                    if (!(valid[l12][l3] && valid[l123][l4]))
                        continue;

                
                    ret.emplace_back(s);
                    ret.back().insert(ret.back().begin()+l123, '.');
                    ret.back().insert(ret.back().begin()+l12, '.');
                    ret.back().insert(ret.back().begin()+l1, '.');
                }
            }
        }
        return ret;
    }
};
// @lc code=end

