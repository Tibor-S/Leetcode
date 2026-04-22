#include <map>
#include <string>
using std::string;
using std::map;
/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    map<char, int> tcount {};
    map<char, int> scount {};
    int tunique = 0;
    int sdone = 0;

    string minWindow(string s, string t) {
        for (char tc : t) {
            if (tcount[tc] == 0) tunique++;
            tcount[tc]++;
        }

        auto begin = s.begin();
        while (begin != s.end()) {
            if (tcount.contains(*begin)) {
                break;
            }
            begin++;
        }

        if (begin == s.end()) return "";

        if (tunique == 1 && tcount[*begin] == 1) {
            return string(begin, begin + 1);
        }

        scount[*begin]++;
        if (scount[*begin] == tcount[*begin])
            sdone++;

        auto end = begin+1;

        maximize_end(end, s, t);
        minimize_begin(begin, s, t);

        if (end == s.end()) {
            if (sdone == tunique)
                return string(begin, end);
            else return "";
        }

        int mn = end - begin;
        auto mn_begin = begin;
        auto mn_end = end;

        while (end != s.end()) {
            scount[*(begin++)]--;
            sdone--;

            maximize_end(end, s, t);
            minimize_begin(begin, s, t);
            
            if (sdone == tunique) {
                if (end - begin < mn) {
                    mn = end - begin;
                    mn_begin = begin;
                    mn_end = end;
                }
            }
        }

        return string(mn_begin, mn_end);
    }

    void minimize_begin(auto &begin, string &s, string &t) {
        while (!tcount.contains(*begin) || --scount[*begin] >= tcount[*begin]) 
            begin++;
        scount[*begin]++;
    }
    void maximize_end(auto &end, string &s, string &t) {
        while (end != s.end() && sdone != tunique) {
            if (tcount.contains(*end)) {
                if (++scount[*end] == tcount[*end])
                    sdone++;
            }
            end++;
        } 
    }

};
// @lc code=end

