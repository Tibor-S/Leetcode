#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////


//  1   2   1   4   =>  1   1   2   3   
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) return 1;
        int sum = 0;
        int previous = 0;


        int peak_pot;

        if (ratings[0] > ratings[1]) {
            peak_pot = 1;
            previous = 1;
        } else {
            sum += 1;
            previous = 1;
        }
        for (int i = 1; i < ratings.size() - 1; i++) {
            if (ratings[i - 1] == ratings[i]) { // plateu from previous
                if (ratings[i] > ratings[i + 1]) { // peak
                    peak_pot = 1;
                    previous = 1;
                } else { // reset
                    sum += 1;
                    previous = 1;
                } 
            } else if (ratings[i - 1] < ratings[i]) { // rising
                if (ratings[i] > ratings[i + 1]) { // peak
                    peak_pot = previous + 1;
                    previous = 1;
                } else { // increment
                    sum += ++previous;
                } 
            } else { // falling
                if (ratings[i] <= ratings[i + 1]) { // valley bottom
                    int slope_final = previous + 1;
                    if (slope_final < peak_pot) {
                        sum += peak_pot + previous * (previous + 1) / 2;
                    } else {
                        sum += (slope_final) * (slope_final + 1) / 2;
                    }
                    previous = 1;
                } else { // increment
                    previous++;
                } 
            }
        }
        if (ratings[ratings.size() - 2] < ratings[ratings.size() - 1]) {
            sum += ++previous;
        } else if (ratings[ratings.size() - 2] > ratings[ratings.size() - 1]) {
            int slope_final = previous + 1;
            if (slope_final < peak_pot) {
                sum += peak_pot + previous * (previous + 1) / 2;
            } else {
                sum += (slope_final) * (slope_final + 1) / 2;
            }
        } else {
            sum += 1;
        }

        return sum;
    }
};