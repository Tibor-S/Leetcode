#include <algorithm>
#include <array>
#include <string>
#include <unordered_map>
#include <vector>
using std::string;
using std::vector;
using std::unordered_map;
using std::array;

/*
 * @lc app=leetcode id=1152 lang=cpp
 *
 * [1152] Analyze User Website Visit Pattern
 */

 
// @lc code=start
class Solution {
public:

    unordered_map<string, int> wids {};
    unordered_map<string, int> uids {};
    vector<string> wid_to_website {};
    vector<vector<int>> history {};

    int matching(int pattern[3]) {
        int count = 0;
        for (auto&hist:history) {
            int pi = 0;
            for (auto wid:hist) {
                if (wid == pattern[pi]) {
                    pi++;
                }
                if (pi == 3) {
                    count++;
                    break;
                }
            }
        }

        return count;
    }

    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        for (auto&w:website) {
            if (!wids.contains(w)) {
                wids[w] = wids.size();
                wid_to_website.push_back(w);
            }
        }
        for (auto&u:username) {
            if (!uids.contains(u)) {
                uids[u] = uids.size();
                history.emplace_back();
            }
        }

        vector<array<int, 3>> all {};
        for (int i = 0; i < username.size(); i++) {
            all.push_back({uids[username[i]], wids[website[i]], timestamp[i]});
        }
        std::sort(all.begin(), all.end(), [](auto&l,auto&r){
            return l[2] < r[2]; 
        });

        for (auto&al:all) {
            int uid = al[0], wid = al[1];
            history[uid].push_back(wid);
        }

        int pattern[3];
        int mxc = 0;
        vector<string> ret(3);
        vector<string> web_pattern(3);
        for (auto&[_,wid]:wids) {
            pattern[0] = wid;
            for (auto&[_,wid]:wids) {
                pattern[1] = wid;
                for (auto&[_,wid]:wids) {
                    pattern[2] = wid;
                    int c = matching(pattern);
                    if (c > mxc) {
                        mxc = c;
                        ret[0] = wid_to_website[pattern[0]]; 
                        ret[1] = wid_to_website[pattern[1]]; 
                        ret[2] = wid_to_website[pattern[2]];
                    } else if (c == mxc) {
                        web_pattern[0] = wid_to_website[pattern[0]]; 
                        web_pattern[1] = wid_to_website[pattern[1]]; 
                        web_pattern[2] = wid_to_website[pattern[2]];

                        if (web_pattern[0] < ret[0] || (
                            web_pattern[0] == ret[0] && (
                                web_pattern[1] < ret[1] || (
                                web_pattern[1] == ret[1] && (
                                    web_pattern[2] < ret[2]
                                )
                            )
                        ))) {
                            ret = web_pattern;
                        }
                    }
                }
            }
        }

        return ret;
    }
};
// @lc code=end

