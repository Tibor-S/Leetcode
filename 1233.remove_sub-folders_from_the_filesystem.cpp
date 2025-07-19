#include <algorithm>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ret {};
        std::sort(folder.begin(), folder.end());
        
        string t = "/$";
        string &root = t;
        for (auto &path : folder) {

            if (path.length() < root.length()) {
                root = path;
                ret.push_back(path);
                continue;
            }

            bool new_root = false;
            int i = 0;
            for (; i < root.length(); i++) {
                if (path[i] == root[i]) continue;
                new_root = true;
            }
            if (path[i] != '/') new_root = true;

            if (new_root) {
                root = path;
                ret.push_back(path);
            }
        }
        
        return ret;
    }
};