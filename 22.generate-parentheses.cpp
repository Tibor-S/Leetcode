#include <iterator>
#include <string>
#include <unordered_set>
#include <vector>
using std::vector;
using std::string;
using std::unordered_set;

/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

/*
1   ()
2   ()()            (())
3   ()()()  (()())  ()(())  (())()  ((()))
4:
()()()
    []()()()    ([])()()    ()[]()()    ()([])()    ()()[]()    ()()([])    ()()()[]
(()())
    [](()())    ([]()())    (([])())    (()[]())    (()([]))    (()()[])    (()())[]




*/

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int src = n;
        unordered_set<string> holder[2] {};
        holder[src&1].emplace("()");
        while (--n) {
            holder[n&1].clear();
            for (auto&org:holder[src&1]) {
                for (auto i = 0; i < org.length()+1; i++) {
                    string ns = org;
                    auto it = ns.begin();
                    std::advance(it, i);
                    ns.insert(it++, '(');
                    ns.insert(it++, ')');
                    holder[n&1].insert(ns);
                }
            }
            src = n;
        }
        return vector(holder[src&1].begin(), holder[src&1].end());
    }
};
// @lc code=end

