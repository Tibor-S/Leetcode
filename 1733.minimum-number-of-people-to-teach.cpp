#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    using V = vector<vector<int>>;
    int n;
    void sharing_langs(V& languages, V& missing_languages, int i, int j) {
        vector<int>& i_languages = languages[i];
        vector<int>& j_languages = languages[j];

        for (int lang:i_languages)
            if(std::binary_search(j_languages.begin(), j_languages.end(), lang))
                return;
        
        auto i_has_language = i_languages.begin();
        auto j_has_language = j_languages.begin();
        for (int lang = 0; lang < n; lang++) {
            if (i_has_language != i_languages.end() && *i_has_language < lang)
                i_has_language++;
            if (i_has_language == i_languages.end() || lang != *i_has_language)
                missing_languages[lang][i]++;
            if (j_has_language != j_languages.end() && *j_has_language < lang)
                j_has_language++;
            if (j_has_language == j_languages.end() || lang != *j_has_language)
                missing_languages[lang][j]++;
        }
    }

    int minimumTeachings(int n, V& languages, V& friendships) {
        this->n = n;
        int m = languages.size();
        V missing_languages(n);
        for (auto&lang:missing_languages) 
            lang.resize(m);
        for (auto&langs:languages) {
            for (auto&lang:langs)
                lang -= 1;
            std::sort(langs.begin(), langs.end());
        }
        for (auto&fren:friendships) {
            fren[0] -= 1; 
            fren[1] -= 1;
            sharing_langs(languages, missing_languages, fren[0], fren[1]);
        }
        int mn = INT32_MAX;
        for (auto&lang:missing_languages) {
            mn = std::min(m - (int)std::count(lang.begin(),lang.end(), 0), mn);
        }
        
        return mn;
    }
};