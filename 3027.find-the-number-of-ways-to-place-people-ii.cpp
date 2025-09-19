#include <algorithm>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

using P = vector<int>&;
int x(P p) { return p[0];}
int y(P p) { return p[1];}
bool within(P ul, P bl, P mid) {
    return !(x(ul) > x(mid) 
        || y(ul) < y(mid)
        || x(bl) < x(mid)
        || y(bl) > y(mid));
}
int diagonal(P p) {
    return y(p) - x(p);
}

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](P l, P r){
            return std::less()(diagonal(l), diagonal(r)); 
        });
        int tot = 0;
        for (int bli = 0; bli < points.size(); bli++) {
            P bl = points[bli];
            for (int uli = bli+1; uli < points.size(); uli++) {
                P ul = points[uli];
                if (x(ul) > x(bl) || y(ul) < y(bl))
                    continue;
                bool close = true;
                for (int midi = bli+1; midi < uli; midi++) {
                    P mid = points[midi];
                    if (within(ul, bl, mid)) {
                        close = false;
                        break;
                    }
                }
                if (close) tot++;
            }
        }
        return tot;
    }
};