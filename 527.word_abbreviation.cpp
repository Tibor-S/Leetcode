#include <algorithm>
#include <functional>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////
struct Abbr {
    string prefix;
    char suffix;
    int filler;

    Abbr(string original) : prefix(1, original[0]), suffix(original.back()), filler(original.length() - 2) {
        filler = std::max(filler, 0);
    }
    // Abbr(Abbr abbr, string original) : prefix(abbr.prefix), suffix(abbr.suffix), filler(abbr.filler -1) {
    //     prefix.append(1, original[prefix.length()]);
    //     filler = std::max(0, filler);
    // }

    void extend(string& original) {
        if (!filler) return;
        prefix.append(1, original[prefix.length()]);
        filler = std::max(filler - 1, 0);
    }

    string combine(string& original) {
        string n(prefix);
        if (filler) {
            n.append(std::to_string(filler));
        }
        n.append(1, suffix);
        
        if (n.size() == original.size()) return original;
        
        return n;
    }
};

template<>
struct std::equal_to<Abbr> {
    constexpr bool operator()(const Abbr& lhs, const Abbr& rhs) const 
{
    return lhs.prefix == rhs.prefix && lhs.filler == rhs.filler && lhs.suffix == rhs.suffix;
}
};

template<>
struct std::hash<Abbr> {
    std::size_t operator()(const Abbr& a) const noexcept
    {
        std::size_t h1 = std::hash<std::string>{}(a.prefix);
        std::size_t h2 = std::hash<char>{}(a.suffix);
        std::size_t h3 = std::hash<int>{}(a.filler);
        return h1 ^ ((h2 ^ (h3 << 1)) << 1); // or use boost::hash_combine
    }
};

class Solution {
public:
    std::unordered_map<Abbr, int> abbr_count {};      


    vector<string> wordsAbbreviation(vector<string>& words) {
        vector<Abbr> abbrs(words.begin(), words.end());


        for (auto& abbr : abbrs) {
            abbr_count[abbr]++;
        }

        bool done = false;
        while (!done) {
            done = true;
            for (int i = 0; i < words.size(); i++) {
                auto& original = words[i];
                auto& abbr = abbrs[i];
                int count = abbr_count[abbr];
                if (count > 1) {
                    done = false;
                    abbr.extend(original);
                    abbr_count[abbr]++;
                }
            }
        }

        for (int i = 0; i < words.size(); i++) {
            words[i] = abbrs[i].combine(words[i]);
        }

        return words;
    }
};