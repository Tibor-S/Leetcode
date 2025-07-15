#include <string>
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;

        bool vowel = false;
        bool consonant = false;
        for (char c : word) {
            if (48 <= c && c <= 57) continue;
            switch (c) {
                case 'a':
                case 'A':
                case 'e':
                case 'E':
                case 'i':
                case 'I':
                case 'o':
                case 'O':
                case 'u':
                case 'U':
                    vowel = true;
                    break;
                case '@':
                case '#':
                case '$':
                    return false;
                default:
                    consonant = true;
            }
        }

        return vowel && consonant;
    }
};