#include <sstream>
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;
using std::stringstream;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Spreadsheet {
public:
    char col_begin = 'A';
    char col_end = 'Z' + 1;

    unordered_map<string, int> grid {};

    Spreadsheet(int rows) {}
    
    void setCell(string cell, int value) {
        grid[cell] = value;
    }
    
    void resetCell(string cell) {
        grid[cell] = 0;
    }
    
    int getValue(string formula) {
        int x, y;
        stringstream ss(formula);
        ss.seekg(1); // skip '='
        string temp = "";

        std::getline(ss, temp, '+');
        x = col_begin <= temp[0] && temp[0] < col_end ? 
            grid[temp] : 
            std::stoi(temp);
        std::getline(ss, temp, '+');
        y = col_begin <= temp[0] && temp[0] < col_end ? 
            grid[temp] : 
            std::stoi(temp);

        return x + y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */