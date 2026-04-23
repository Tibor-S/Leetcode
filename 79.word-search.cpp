#include <string>
#include <vector>
using std::vector;
using std::string;
/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#define GET(board, c) board[Y(c)][X(c)]
#define SET(board, c, val) board[Y(c)][X(c)] = val
#define X(c) (c)[0]
#define Y(c) (c)[1]
#define N(c) ((int[2]) {(c)[0], (c)[1]-1})
#define E(c) ((int[2]) {(c)[0]+1, (c)[1]})
#define S(c) ((int[2]) {(c)[0], (c)[1]+1})
#define W(c) ((int[2]) {(c)[0]-1, (c)[1]})
#define NL(c) ((int[2]) {0, (c)[1]+1})
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        return move((int[2]) {0,0}, board, word);
    }
    bool match(int c[2], vector<vector<char>>& board, const char *word) {
        if (X(c) < 0 || X(c) >= board[0].size() 
            || Y(c) < 0 || Y(c) >= board.size())
            return false;

        char val = GET(board, c);
        if (val != word[0])
            return false;

        word++;
        if (*word == '\0')
            return true;

        SET(board, c, -1);

        if (match(N(c), board, word)
            || match(E(c), board, word)
            || match(S(c), board, word)
            || match(W(c), board, word))
            return true;
            
        SET(board, c, val);
        
        return false;
    }
    bool move(int c[2], vector<vector<char>>& board, string word) {
        if (X(c) >= board[0].size())
            return move(NL(c), board, word);
        if (Y(c) >= board.size())
            return false;
        if (match(c, board, word.c_str()))
            return true;
        return move(E(c), board, word);
    }
};
// @lc code=end

