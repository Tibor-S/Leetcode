
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int tribonacci(int n) {
        int _3 = 0;
        int _2 = 1;
        int _1 = 1;
        if (n == 0) return _3;
        if (n == 1) return _2;
        for (int i = 2; i < n; i++) {
            int t = _3 + _2 + _1;
            _3 = _2;
            _2 = _1;
            _1 = t;
        }
        return _1;
    }
};