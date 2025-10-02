#include <string>
#include <unordered_map>
#include <vector>
using std::vector;
using std::string;
using std::unordered_map;

/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
    int w_len;
    unordered_map<string, int> window {};
    void remove(string& s, int* first, string& rem, int*tot) {
        string curr = s.substr(*first, w_len);
        (*first) += w_len;
        while (curr != rem) {
            window[curr]--;
            curr = s.substr(*first, w_len);
            (*first) += w_len;
            (*tot)--;
        } 
        window[curr]--;
        (*tot)--;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        w_len = words[0].length();
        unordered_map<string, int> lex {};
        for (auto&w:words) 
            lex[w]++;
        vector<int> ret {};


        for (int org = 0; org < w_len; org++) {
            window.clear();
            int first = org;
            int tot = 0;
            for (int i = org; i < s.length(); i += w_len) {
                string curr = s.substr(i, w_len);
                if (!lex.contains(curr)) {
                    first = i+w_len;
                    window.clear();
                    tot = 0;
                    continue;
                } 

                window[curr]++;
                tot++;
                if (window[curr] > lex[curr]) {
                    remove(s, &first, curr, &tot);
                    continue;
                }

                if (tot == words.size()) {
                    ret.push_back(first);
                    window[s.substr(first, w_len)]--;
                    first += w_len;
                    tot--;
                }
            }
        }

        return ret;
    }
};
// @lc code=end

