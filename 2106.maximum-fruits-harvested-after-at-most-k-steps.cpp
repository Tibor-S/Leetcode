#include <algorithm>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    static bool find_pos(vector<int> &elem, int val) {
        return elem[0] < val;
    }
    static bool upper_pos(int val, vector<int> &elem) {
        return val < elem[0];
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        auto first = std::lower_bound(fruits.begin(), fruits.end(), startPos-k, Solution::find_pos);
        auto mid = std::lower_bound(fruits.begin(), fruits.end(), startPos, Solution::find_pos);
        auto last = std::upper_bound(fruits.begin(), fruits.end(), startPos+k, Solution::upper_pos);
        
        // adjust pos

        auto it = first;
        while (it != mid) {
            it->at(0) = startPos - it->at(0);
            it++;
        }
        while (it != last) {
            it->at(0) -= startPos;
            it++;
        }

        // take all left
        it = first;
        int ltot = 0;
        while (it != mid) {
            ltot += (it++)->at(1);
        }
        // take all right
        it = mid;
        int rtot = 0;
        while (it != last) {
            rtot += (it++)->at(1);
        }
        // mx
        int mx = std::max(ltot, rtot);

        // first left then right
        it = first;
        auto rit = mid;
        int lrtot = ltot;
        while (rit != last) {
            int steps = 2 * it->at(0) + rit->at(0); 
            while (it != mid && steps > k) {
                lrtot -= (it++)->at(1);
                steps = 2 * it->at(0) + rit->at(0);
            }
            if (it == mid) break;
            lrtot += rit->at(1);
            mx = std::max(lrtot, mx);
            rit++;
        }
        
        // first right then left
        it = first;
        rit = mid;
        lrtot = ltot;
        while (rit != last) {
            int steps = it->at(0) + 2 * rit->at(0); 
            while (it != mid && steps > k) {
                lrtot -= (it++)->at(1);
                steps = it->at(0) + 2 * rit->at(0);
            }
            if (it == mid) break;
            lrtot += rit->at(1);
            mx = std::max(lrtot, mx);
            rit++;
        }
        
        return mx;
    }
};

// class Solution {
// public:
//     int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
//         auto mid = std::lower_bound(fruits.begin(), fruits.end(), startPos, [](auto &elem, int val ){
//             return elem[0] < val;
//         });
//         int tot = 0;
//         auto left = mid;
//         auto right = mid;
//         auto lend = fruits.begin();
//         left--;
//         lend--;
//         int lsum = 0;
//         int rsum = 0;
//         while (left != lend) {
//             left->at(0) = startPos - left->at(0);
//             lsum += left->at(1);
//             left->at(1) = lsum;
//             left--;
//         } 
//         while (right != fruits.end()) {
//             right->at(0) = right->at(0) - startPos;
//             rsum += right->at(1);
//             right->at(1) = rsum;
//             right++;
//         }

//         return 0;
//     }
// };