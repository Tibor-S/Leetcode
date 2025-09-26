#include <sstream>
#include <string>
using std::string;
using std::stringstream;

/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        stringstream ss {};
        int x = num / 1000;
        for (int i = 0; i < x; i++)
            ss << 'M';
        num -= x * 1000;
        while (100 <= num) {
            if (900 <= num) {
                ss << 'C' << 'M';
                num -= 900;
            } else if (500 <= num) {
                ss << 'D';
                num -= 500;
            } else if (400 <= num) {
                ss << 'C' << 'D'; 
                num -= 400;
            } else {
                ss << 'C';
                num -= 100;
            }
        }
        while (10 <= num) {
            if (90 <= num) {
                ss << 'X' << 'C';
                num -= 90;
            } else if (50 <= num) {
                ss << 'L';
                num -= 50;
            } else if (40 <= num) {
                ss << 'X' << 'L'; 
                num -= 40;
            } else {
                ss << 'X';
                num -= 10;
            }
        }
        while (num) {
            if (9 == num) {
                ss << 'I' << 'X';
                num -= 9;
            } else if (5 <= num) {
                ss << 'V';
                num -= 5;
            } else if (4 == num) {
                ss << 'I' << 'V'; 
                num -= 4;
            } else {
                ss << 'I';
                num -= 1;
            }
        }

        return ss.str();
    }
};
// @lc code=end

