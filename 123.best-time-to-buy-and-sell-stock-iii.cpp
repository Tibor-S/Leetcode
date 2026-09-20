#include <algorithm>
#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

/*

case when arr is 1
a   => 0

case when arr is 2
Arr[1]      | ab        | ba    
a-a a-a a   | a-a   b-a | a-a   a-a

results:
a-a a-a
a-a b-a

case when arr is 3
Arr[1]  
x-y s-t L   | c > x,s   | c > x,t   | c > x   
a-a a-a b   | 
a-a b-a b   | 

case when arr is 3  | a <= b <= c
a   b   c   => c-a
b   a   c   => c-a
a   c   b   => c-a
b   c   a   => c-b
c   a   b   => b-a
c   b   a   => 0

case when arr is 4  | a <= b <= c <= d
a   b   c   d   => d-a
b   a   c   d   => d-a
a   c   b   d   => c-a  d-b
b   c   a   d   => c-b  d-a
c   a   b   d   => d-a
c   b   a   d   => d-a
a   b   d   c   => d-a
b   a   d   c   => d-a
a   c   d   b   => d-a
b   c   d   a   => d-b
c   a   d   b   => d-a
c   b   d   a   => d-b
a   d   b   c   => d-a  c-b
b   d   a   c   => d-b  c-a
a   d   c   b   => d-a
b   d   c   a   => d-b
c   d   a   b   => d-c  b-a
c   d   b   a   => d-c
d   a   b   c   => c-a   
d   b   a   c   => c-a
d   a   c   b   => c-a
d   b   c   a   => c-b
d   c   a   b   => b-a
d   c   b   a   => 0

case when arr is 5:
ARR[4]- --------------5-th-ranking-----------------------------
vvvvvvv | abcde     | abced     | abecd     | aebcd     | eabcd
c-a *** | 
c-b ***
c-a d-b
c-b d-a
c-a d-b
d-a ***
d-b ***
d-c ***
d-a c-b
d-b c-a
d-c b-a 



1   2   4   2   5   7   2   4   9   0



1   2   4   2   5   7   2   4   9   0
l       h   l       h   l       h                                   

3 entries:
        1,4     2,7     2,9
sep1    1,4     1,4     1,7             
sep2    0,0     2,7     2,9   
combo   1,4     1,7     1,9
best:   3       8       13


Kinds:

- o -   PEAK
o o -   PEAK

o o +   VALLEY
+ o +   VALLEY

- o o   PLATEAU
o o o   PLATEAU
+ o o   PLATEAU

- o +   INCREASE
+ o -   DECREASE


    1   2   4   2   5   7   2   4   9   0

l1: 0,1 0,1 0,1 0,1 0,1 0,1 0,1 0,1 0,1 9,0
h1: 0,1 1,2 2,4 2,4 4,5 5,7 5,7 5,7 8,9 9,0

mp:    0   0
l2: 0,1 1,2 2,4 3,2 4,5 5,7 6,2 6,2 8,9 9,0
h2: 0,1 1,2 2,4 3,2 4,5 5,7 6,2 7,4 8,9 9,0


forward walk --->
1   2   4   2   5   7   2   4   9   0
1,1 1,2 1,4 1,4 1,5 1,7 1,7 1,7 1,9 1,9
0   1   3   3   4   6   6   6   8   8

back walk <-----
1   2   4   2   5   7   2   4   9   0
1,9 2,9 2,9 2,9 2,9 2,9 2,9 4,9 9,9 0,0
8   7   7   7   7   7   7   5   0   0



1   2   4   2   5   7   2   4   9   0
                                    1,9|0,0
                                1,9|0,0
                            1,4|9,9
                        1,4|4,9
                    1,7|2,9




                            1,7|9,9
                        1,7|4,9
                    1,7|2,9
                1,5|2,9
            1,4|2,9
        1,4|2,9
    1,2|2,9
1,1|2,9
1,1|1,9
*/



// @lc code=start

typedef struct T {
    int low;
    int high;

    int profit() const { return high - low; }
} trans_t;
typedef struct W {
    trans_t forward;
    trans_t backward;

    int profit() const { return forward.profit() + backward.profit(); }
} walked_t;

class Solution {
    walked_t walked[100000] {};
public:
    int maxProfit(vector<int>& prices) {
        forward(prices);
        backward(prices);
        int mx = 0;
        for (int i = 0; i < prices.size(); i++) {
            int profit = walked[i].profit();
            mx = std::max(profit, mx);
        }
        return mx;
    }

    void forward(vector<int>& prices) {
        // At index i optimal.profit >= optimistic.profit
        // optimial.low > optimistic.low
        trans_t optimal {prices[0], prices[0]};
        walked[0].forward = optimal;
        trans_t optimistic = optimal;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < optimistic.low) {
                optimistic.low = prices[i];
                optimistic.high = prices[i];
            } else {
                optimal.high = std::max(prices[i], optimal.high);
                optimistic.high = std::max(prices[i], optimistic.high);

                if (optimistic.profit() > optimal.profit()) {
                    optimal = optimistic;
                }
            }

            walked[i].forward = optimal;
        }
    }

    void backward(vector<int>& prices) {
        int last = prices.size() -1;

        // At index i optimal.profit >= optimistic.profit
        // optimial.high < optimistic.high
        trans_t optimal {prices[last], prices[last]};
        walked[last].backward = optimal;
        trans_t optimistic = optimal;

        for (int i = last-1; i >= 0; i--) {
            if (prices[i] > optimistic.high) {
                optimistic.low = prices[i];
                optimistic.high = prices[i];
            } else {
                optimal.low = std::min(prices[i], optimal.low);
                optimistic.low = std::min(prices[i], optimistic.low);

                if (optimistic.profit() > optimal.profit()) {
                    optimal = optimistic;
                }
            }

            walked[i].backward = optimal;
        }
    }
};
// @lc code=end

