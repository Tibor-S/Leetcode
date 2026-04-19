#include <string>
using std::string;

/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
#define EMPTY(it, end) ((it) == (end))
#define S_EMPTY(sit) EMPTY(sit, send)
#define P_EMPTY(pit) EMPTY(pit, pend)
#define WILDCARD(pit) (*(pit) == '*')
#define REMOVE_WILDCARDS(pit) while (WILDCARD(pit)) {(pit)++;}
#define REMOVE_WILDCARDS_BACK(pend) while (WILDCARD(pend - 1)) {(pend)--;}
#define ANY(pit) (*(pit) == '?')
#define CHAR(sit, pit) (*(sit) == *(pit))
class Solution {
public:
    bool isMatch(string s, string p) {
        auto sbegin = s.begin();
        auto send = s.end();
        auto pbegin = p.begin();
        auto pend = p.end();
        bool wildcards = false;

        while (!P_EMPTY(pbegin)) {
            if (WILDCARD(pbegin)) {
                wildcards = true;
                REMOVE_WILDCARDS(pbegin);
                break;
            } else if (S_EMPTY(sbegin)) {
                return false;
            } else if (CHAR(sbegin, pbegin) || ANY(pbegin)) {
                sbegin++;
                pbegin++;
            } else {
                return false;
            }
        }

        while (!P_EMPTY(pbegin)) {
            if (WILDCARD(pend - 1)) {
                wildcards = true;
                REMOVE_WILDCARDS_BACK(pend);
                break;
            } else if (S_EMPTY(sbegin)) {
                return false;
            } else if (CHAR(send - 1, pend - 1) || ANY(pend - 1)) {
                send--;
                pend--;
            } else {
                return false;
            }
        }

        if (!wildcards && !S_EMPTY(sbegin)) {
            return false;
        }

        if (P_EMPTY(pbegin))
            return true;

        auto ptst = pbegin;
        while (!P_EMPTY(ptst)) {
            if (WILDCARD(ptst)) {
                int len = ptst - pbegin;
                if (send - sbegin < len) 
                    return false;

                bool match = true;
                auto sit = sbegin;
                auto pit = pbegin;
                for (int i = 0; i < len; i++) {
                    if (!(CHAR(sit, pit) || ANY(pit))) {
                        match = false;
                        break;
                    }
                    sit++; pit++;
                }

                if (match) {
                    sbegin += len;
                    REMOVE_WILDCARDS(ptst);
                    pbegin = ptst;
                } else {
                    sbegin++;
                }
            } else if (S_EMPTY(sbegin)) {
                return false;
            } else {
                ptst++;
            }
        }

        int len = ptst - pbegin;
        while (send - sbegin >= len) {
            bool match = true;
            auto sit = sbegin;
            auto pit = pbegin;
            for (int i = 0; i < len; i++) {
                if (!(CHAR(sit, pit) || ANY(pit))) {
                    match = false;
                    break;
                }
                sit++; pit++;
            }

            if (match) {
                return true;
            } else {
                sbegin++;
            }
        }

        return false;
    }
};
// @lc code=end

