#include <string>
#include <vector>
using std::string;
using std::vector;
/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
#define REMOVE_SLASH(p) while ((p) != "" && (p).at(0) == '/') (p) = (p).substr(1)
class Solution {
public:
    string simplifyPath(string path) {
        REMOVE_SLASH(path);

        vector<string> absolute {};
        while (path != "") {
            string name = parse(&path);
            if (name == ".") continue;
            if (name == "..") {
                if (absolute.size() > 0) 
                    absolute.pop_back();
                continue;
            } 
            absolute.push_back(name);
        }

        if (absolute.empty()) return "/";

        string ret = "";
        for (string name : absolute) {
            ret.push_back('/');
            ret.append(name);
        }

        return ret;
    }

    string parse(string *path) {
        for (int i = 0; i < path->length(); i++) {
            if (path->at(i) == '/') {
                string ret = path->substr(0, i);
                *path = path->substr(i);
                REMOVE_SLASH(*path);
                return ret;
            }
        }
        string ret = path->substr(0);
        *path = "";
        return ret;
    }
};
// @lc code=end

