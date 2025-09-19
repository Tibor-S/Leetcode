#include <algorithm>
#include <map>
#include <string>
#include <utility>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

k = 2 

k = 2
l   e   t   s   l   e   e   t   c   o   d   e
0   1   2   3   4   5   6   7   8   9   10  11


e:  1   5   6  11
l:  0   4
t:  2   7 

0   0   0
0   1   0
0   1

l = 3
t   l   e
t   e   l
t   e   e
l   t   e
l   e   t
l   e   e
e   t   l
e   t   e
e   l   t
e   l   e
e   e   t
e   e   l

l = 4
t   l   e   e
t   e   l   e
t   e   e   l
l   t   e   e
l   e   t   e
l   e   e   t
e   t   l   e
e   t   e   l
e   l   t   e
e   l   e   t
e   e   t   l
e   e   l   t   

c   S1  E1  S2  E2
l   0   4   4   12
e   1   4   5   12
t   2   4   7   12   

c   S1  E1  S2  E2  c   S1  E1  S2  E2  c   S1  E1  S2  E2  c   S1  E1  S2  E2
e   1   6   6   12  
                    l   XXX
                    e   5   6   11  12
                                        l   XXXX
                                        e   XXXX
                                        t   XXXX
                    t   
                                     
        
l:  0   4
e:  1   5   6  11
t:  2   7 

le: 1   5
lt: 2   7
ee: 5   11
et: 2   7
te: 5   11

let: 2  7
ete: 5  11


*/

class Solution {
public:
    struct sub {
        int lb;
        int hb;
        int end;
    };

    string *ss;
    int kk;
    int mlen;
    std::map<char, vector<int>> cstart {};
    vector<sub> tttt;

    int count(char letter) { return cstart[letter].size() / kk; }

    bool valid(vector<char> &alpha, vector<char>& word, vector<int>& indices) {
        vector<char> t(alpha);
        int d = 1;
        auto iit = indices.end();
        for (int wi = 0; wi < word.size(); wi++) {
            int ti = *(--iit);
            word[wi] = t[ti];
            t.erase(t.begin() + ti); 
        }
        int last = -1;
        for (int k = 0; k < kk; k++) {
            for (char c : word) {
                auto it = std::upper_bound(cstart[c].begin(), cstart[c].end(), last);
                if (it == cstart[c].end()) return false;
                last = *it;
            }
        }

        return true;
    }

    int fac(int n) {
        int prod = 1;
        while(n) prod *= n--;
        return prod;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        ss = &s;
        kk = k;
        mlen = ss->size() / kk;
        string mx = "";
        for (int i = 0; i < s.length(); i++) {
            cstart[s[i]].push_back(i);
        }
        std::vector<char> rem;
        for (auto &[id, starts] : cstart) {
            if (starts.size() < k) rem.push_back(id);
        }
        for (auto &id : rem) cstart.erase(id);
        auto it = cstart.end();
        std::vector<char> alpha {};
        while (it-- != cstart.begin()) {
            int count = it->second.size() / kk;
            for (int i = 0; i < count; i++) alpha.push_back(it->first);
        }

        vector<char> word {};
        vector<int> indices(alpha.size(), 0);
        int lps = fac(alpha.size());
        int off = 0;
        for (int len = alpha.size(); len >= 0; len--) {
            word.resize(len);
            for (int i = 0; i < lps; i ++) {
                if (valid(alpha, word, indices)) return string(word.begin(), word.end());
                for (int i = 0; i < indices.size(); i++) {
                    if (indices[i] == i + off) {indices[i] = 0; continue;}
                    indices[i]++;
                    break;
                }
            }
            indices.pop_back();
            off++;
            lps /= alpha.size() - word.size() + 1;
            std::fill(indices.begin(), indices.end(), 0);
        }



        return "";
    }
};

// class Solution {
// public:
//     string longestSubsequenceRepeatedK(string s, int k) {
//         std::map<char, vector<int>> exts;
//         std::map<string, vector<int>> indices;
//         std::map<string, vector<int>> indices2;
        
//         for (int i = 0; i < s.length(); i++) {
//             exts[s[i]].push_back(i);
//         }

//         std::vector<char> rem {};
//         for (auto &[id, is] : exts) {
//             if (is.size() < k) rem.push_back(id);
//         }

//         for (auto &id : rem) exts.erase(id);

//         // Add len = 2; doubles
//         for (auto &[id, is] : exts) {
//             int step = is.size() / k;
//             if (step < k) continue;
//             string nid(2, id);
//             for (int first = 0; first < is.size(); first += step) {
//                 int end = first + step; 
//                 for (int second = first + 1; second < end; second++) {
//                     indices[nid].push_back(is[second]);
//                 }
//             }
//         }

//         for (auto &[id, is] : exts) {
//             for (auto &[toid, tois] : exts) {
//                 if (toid == id) continue;

//                 string nid (1, id);
//                 nid.append(1, toid);
                
//                 auto it = tois.begin();
//                 for (int start : is) {
//                     it = std::upper_bound(it, tois.end(), start);
//                     if (it == tois.end()) break;
//                     indices[nid].push_back(*it++);
//                 }
//                 if (indices[nid].size() < k) indices.erase(nid);
//             }
//         }

//         std::map<string, vector<int>> *current = &indices;
//         std::map<string, vector<int>> *passive = &indices2;
//         while (!current->empty()) {
//             passive->clear();
//             for (auto &[id, is] : *current) {
//                 for (auto &[ext, extis] : exts) {
//                     string nid (id);
//                     nid.append(1, ext);
//                     auto it = extis.begin();
//                     for (int start : is) {
//                         it = std::upper_bound(it, extis.end(), start);
//                         if (it == extis.end()) break;
//                         (*passive)[nid].push_back(*it++);
//                     }
//                     if ((*passive)[nid].size() < k) passive->erase(nid);
//                 }
//             }
//             auto t = current;
//             current = passive;
//             passive = t;
//         }




//         return "l";
//     }
// };