#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using std::vector;
using std::string;
using std::unordered_map;
/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ret {};
        for (string s : strs) {
            string key = string(s);
            std::sort(key.begin(), key.end());
            if (ret.contains(key)) {
                ret[key].push_back(s);
            } else {
                ret.insert({key, vector<string> {s}});
            }
        }

        vector<vector<string>> rret {};
        for (auto t : ret) {
            rret.push_back(t.second);
        }

        return rret;
    }
};
// @lc code=end

