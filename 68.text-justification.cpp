
#include <string>
#include <vector>
using std::string;
using std::vector;

struct Line {
    Line *previous;
    string &word;
    int words_len;
    int spaces;

    Line(string& word) : previous(nullptr), word(word), words_len(word.length()), spaces(0) {}
    Line(string& word, Line *previous) : previous(previous), word(word), words_len(previous->words_len + word.length()), spaces(previous->spaces + 1) {}
    ~Line() {
        delete previous;
    }

    static bool appendable(Line *line, string app, int max_width) {
        if (line == nullptr) return true;
        return line->appendable(app, max_width);
    }

    bool appendable(string app, int max_width) {
        return words_len + spaces + 1 + app.length() <= max_width;
    }

    int space(int max_width) {
        return (max_width - words_len) / spaces;
    }

    void fully(string& cont, int max_width) {
        int start = max_width - word.length();
        if (previous == nullptr) start = 0;
        word.copy(cont.data() + start, word.length());
        if (previous != nullptr) 
            previous->fully(cont, max_width - space(max_width) - word.length());
    }

    int left(string& cont) {
        int start = 0;
        if (previous != nullptr) 
            start = previous->left(cont);
        cont.copy(word.data(), word.length(), start);
        return start + word.length() + 1;
    }
};

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret {};
        Line *current = new Line(words[0]);
        for (int i = 1; i < words.size(); i ++) {
            string& word = words[i];
            if (current->appendable(word, maxWidth)) {
                current = new Line(word, current);
            } else {
                ret.emplace_back(maxWidth, ' ');
                current->fully(ret.back(), maxWidth);
                delete current;
                current = new Line(word);
            }
        }
        ret.emplace_back(maxWidth, ' ');
        current->left(ret.back());
        delete current;
        return ret;
    }
};