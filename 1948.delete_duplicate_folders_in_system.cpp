#include <algorithm>
#include <cstddef>
#include <functional>
#include <iterator>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////


struct sub {
    string name;
    vector<sub> children; // sorted
    size_t _hash = 0;

    sub(string n) : name(n), children() {
    }

    void append(sub& s) {children.push_back(s);}
    size_t hash();
};

template<>
struct std::hash<sub>
{
    std::size_t operator()(const sub& s) const noexcept
    {
        if (s._hash != 0) return s._hash;
        auto h = 0;
        for (auto sc : s.children) h = std::hash<sub>{}(sc) ^ (h << 1);
        
        return h == 0 ?  std::hash<string>{}(s.name) : h;
    }
};

size_t sub::hash() {
    size_t h = std::hash<sub>{}(*this);
    this->_hash = h;
    return h;
}

template<>
struct std::equal_to<sub>
{
    std::size_t operator()(const sub& lhs, const sub& rhs) const noexcept
    {
        if (lhs.children.size() == 0 && rhs.children.size() == 0) return lhs.name == rhs.name;
        if (lhs.children.size() != rhs.children.size()) return false;
        for (int i = 0; i < lhs.children.size(); i++) {
            if (lhs.children[i].name != rhs.children[i].name || !std::equal_to<sub>{}(lhs.children[i], rhs.children[i])) return false; 
        }
        return true;
    }
};


size_t combine(size_t h1, size_t h2) {
    return h1 ^ (h2 << 1);
}


class Solution {
public:
    vector<vector<string>> ret;
    typedef decltype(ret.begin()) I;
    I * ti;
    std::unordered_map<sub, int> count;
    typedef decltype(&**ti) P;
    std::unordered_set<sub> include {};


    I upper_bound(I first, I last) {
        int depth = first->size();
        while(++first < last && first->size() > depth);
        // string val = first->back();
        // int depth = (*first).size() - 1;
        // auto count = std::distance(first, last);
        
        // while (count > 0) {
        //     auto it = first;
        //     int step = count / 2;
        //     std::advance(it, step);

        //     int it_depth = (*it).size() - 1;

        //     if (it_depth > depth && val == (*it)[depth]) {
        //         first = ++it;
        //         count -= step+1;
        //     }
        //     else {
        //         count = step;
        //     }
        // }
        return first;
    }
    
    sub search(I parent, I last) {
        sub p(parent->back());
        if (std::distance(parent, last) == 1) {
            p.hash();
            return p;
        }
        I child = parent;
        std::advance(child, 1);
        while (child != last) {
            I end = upper_bound(child, last);
            
            sub ch = search(child, end);
            p.append(ch);
            child = end;
        }

        p.hash();
        count[p]++;
        return p;
    }

    void fill(vector<string> &path, vector<sub>& children) {
        for (auto &s : children) {
            if (count[s] <= 1) {
                path.push_back(s.name);
                ret.emplace_back(path);
                fill(path, s.children);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        std::sort(paths.begin(), paths.end(), [](vector<std::basic_string<char>> &left, vector<std::basic_string<char>> &right){
            int len = std::min(left.size(), right.size());
            int i = 0;
            while (i < len && left[i] == right[i]) i++;
            if (i == len)
                return left.size() < right.size();
            return std::less<std::basic_string<char>>()(left[i], right[i]);
        });

        std::vector<sub> sss;
        I child = paths.begin();
        while (child != paths.end()) {
            I end = upper_bound(child, paths.end());
            sss.emplace_back(search(child, end));
            child = end;
        }
        
        vector<string> p{};
        fill(p, sss);
        return ret;
    }
};