#include <string>
using std::string;
/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

// @lc code=start
#define PLUS(s) ((s)[0] == '+')
#define MINUS(s) ((s)[0] == '-')
#define DOT(s) ((s)[0] == '.')
#define EXP(s) ((s)[0] == 'e' || (s)[0] == 'E')
#define DIGIT(s) ('0' <= (s)[0] && (s)[0] <= '9')
class Solution {
public:
    bool isNumber(string s) {
        remove_pre(&s);
        if (remove_digits(&s)) {
            if (remove_dot(&s)) 
                remove_digits(&s);
        } else {
            if (remove_dot(&s)) {
                if (!remove_digits(&s))
                    return false;
            } else 
                return false;
        }

        if (remove_exp(&s)) {
            remove_pre(&s);
            if (!remove_digits(&s))
                return false;
        }

        return s == "";
    }

    bool remove_pre(string *s) {
        if (PLUS(*s) || MINUS(*s)) {
            *s = s->substr(1);
            return true;
        }
        return false;
    }

    bool remove_digits(string *s) {
        bool t = DIGIT(*s);
        while (DIGIT(*s)) {
            *s = s->substr(1);
        }
        return t;
    }

    bool remove_dot(string *s) {
        if (DOT(*s)) {
            *s = s->substr(1);
            return true;
        }
        return false;
    }

    bool remove_exp(string *s) {
        if (EXP(*s)) {
            *s = s->substr(1);
            return true;
        }
        return false;
    }
};
// @lc code=end

