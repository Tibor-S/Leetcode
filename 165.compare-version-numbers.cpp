#include <sstream>
#include <string>
using std::string;
using std::stringstream;
/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start

struct Revision {
    int rev[500];
    Revision(string revs) {
        int i = 0;
        stringstream ss(revs);
        string t;
        char delim = '.';
        while (getline(ss, t, delim)) {
            rev[i++] = std::stoi(t);
        }
    }
};

class Solution {
public:
    int compareVersion(string version1, string version2) {
        Revision v1(version1), v2(version2);
        for (int i = 0; i < 500; i++) {
            if (v1.rev[i] < v2.rev[i]) return -1;
            if (v1.rev[i] > v2.rev[i]) return 1;
        }
        return 0;
    }
};
// @lc code=end
