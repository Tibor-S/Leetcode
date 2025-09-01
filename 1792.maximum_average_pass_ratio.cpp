#include <queue>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////


/*



pas 1   3   2
tot 2   5   2
rat .5  .6  1
sco .33 .11 0

pas 2   3   2
tot 3   5   2
rat .66 .6  1
sco .13 .11 0

pas 3   3   2
tot 4   5   2
rat .75 .6  1
avg:    0.7833333333



pas 2   3   4   2
tot 4   9   5   10
rat .5  .33 .8  .2
sco .2  .2  .04 .36

pas 2   3   4   3
tot 4   9   5   11
rat .5  .33 .8  .27
sco .2  .2  .04 .22

pas 2   3   4   4
tot 4   9   5   12
rat .5  .33 .8  .27
sco .2  .2  .04 .22



*/

struct R {
    int n, d;
    double score;

    R(int n, int d) : n(n), d(d), score(
        val(1)-val(0)
        //(double) (d * (n + 1)) / (double) (n * (d+1))
    ) {}

    explicit R(const vector<int>& cl) : R(cl[0], cl[1]) {}

    double val(int i = 0) const {
        return (double)(n+i) / (double)(d+i);
    }
};

template<>
struct std::less<R> {
    constexpr bool operator()(const R& lhs, const R& rhs) const 
    {
        return lhs.score < rhs.score; // assumes that the implementation handles pointer total order
}
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        std::priority_queue<R> pq(classes.begin(), classes.end());

        for (int i = 0; i < extraStudents; i++) {
            R t = pq.top();
            pq.emplace(t.n+1,t.d+1);
            pq.pop();
        }

        double tot = 0;
        while (!pq.empty()) {
            tot += pq.top().val();
            pq.pop();
        }
        return tot / classes.size();
    }

};