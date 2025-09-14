#include <algorithm>
#include <array>
#include <cstdint>
#include <map>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::map;
////////////////////////////////////////////////////////////////////////////////////////////////////


const int L = 'z' - 'A' + 1;
std::array<char, 10> vowels = {
    'a', 'e', 'i', 'o', 'u',
    'A', 'E', 'I', 'O', 'U'};
bool is_vowel[L] = {};
void init() {
    is_vowel['A' - 65] 
        = is_vowel['E' - 65] 
        = is_vowel['I' - 65] 
        = is_vowel['O' - 65] 
        = is_vowel['U' - 65] 
        = is_vowel['a' - 65] 
        = is_vowel['e' - 65] 
        = is_vowel['i' - 65] 
        = is_vowel['o' - 65] 
        = is_vowel['u' - 65] 
        = true;
}
bool is_uc(char c) {return c < 97;}
bool is_lc(char c) {return c >= 97;}
char to_uc(char c) {
    if (is_uc(c)) return c;
    return c - 32;
}
char to_lc(char c) {
    if (is_lc(c)) return c;
    return c + 32;
}
enum Error {NONE = 0, CASE, VOWEL, INF};
string EMPTY = "";
struct Tree {
    map<char, Tree> children {};
    vector<std::pair<string, int>> leaf {};

    Tree() {}

    void append(string& s, int si, int i) {
        if (i == s.length()) {
            leaf.emplace_back(s, si); 
            return;
        }
        char c = s[i];
        if (is_vowel[c-65]) {
            children['*'].append(s, si, i+1);
        } else {
            children[c].append(s, si, i+1);
        }
    }

    Error comp(string& s, string& q) {
        if (s == "") return INF;
        Error error = NONE;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == q[i]) continue;
            if (to_lc(q[i]) == s[i] || 
                to_uc(q[i]) == s[i])
            {
                error = std::max(CASE, error);
                continue;
            }
            if (is_vowel[s[i] - 65] && is_vowel[q[i] - 65]) {
                error = std::max(VOWEL, error);
                continue;
            }
            return INF;
        }
        return error;
    }

    std::tuple<string*, int, Error> search(string& q, int i = 0) {
        if (q.size() == i) {

            string* res = &EMPTY;
            int i = INT32_MAX;
            Error error = INF;

            for (auto& [s, si] : leaf) {
                Error nerror = comp(s, q);
                if (nerror < error) {
                    res = &s;
                    i = si;
                    error = nerror;
                }
            }

            return {res, i, error};
        }

        char c = q[i];
        if (is_vowel[c - 65]) {
            return children['*'].search(q, i+1);
        }
        std::tuple<string*, int, Error> resp = children[c].search(q, i+1);
        std::tuple<string*, int, Error> resc = children[is_lc(c) ? to_uc(c) : to_lc(c)].search(q, i+1);
        
        if (std::get<2>(resp) == std::get<2>(resc)) 
            return std::get<1>(resp) < std::get<1>(resc) ? resp : resc;
        else
            return std::get<2>(resp) <= std::get<2>(resc) ? resp : resc;

    }
};
class Solution {
public:
    Tree tree {};
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        init();
        for(int i = 0; i < wordlist.size(); i++) {
            tree.append(wordlist[i], i, 0);
        }
        vector<string> ret {};
        for (auto& q:queries) {
            ret.push_back(*std::get<0>(tree.search(q)));
        }
        return ret;
    }
};