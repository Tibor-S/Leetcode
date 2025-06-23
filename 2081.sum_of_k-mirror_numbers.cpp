
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> vec {};
    long long kMirror(int k, int n) {
        long long prefix = 1;
        long long inc = 1;
        long long lim = 1;
        long long s = 0;
        while (true) {
            lim *= 10;
            while (prefix < lim) {
                long long num = prefix + gen_suffix(prefix / inc, true);
                if (is_mirrored_k(num, k)) {
                    s += num;
                    n--;
                    if (!n) return s;
                }
                prefix += inc;
            }

            inc *= 10;
            lim *= 10;

            while (prefix < lim) {
                long long num = prefix + gen_suffix(prefix / inc, false);
                if (is_mirrored_k(num, k)) {
                    s += num;
                    n--;
                    if (!n) return s;
                }
                prefix += inc;
            }
        }
    }

    long long gen_suffix(long long prefix, bool skip_1) {
        if (skip_1) prefix /= 10;
        long suffix = 0;
        while (prefix) {
            suffix *= 10;
            suffix += prefix % 10;
            prefix /= 10;
        }

        return suffix;
    }

    bool is_mirrored_k(long long prefix, int k) {
        vec.clear();
        while(prefix) {
            vec.push_back(prefix % k);
            prefix /= k;
        }
    
        auto left = vec.begin();
        auto right = vec.end();
        while (left != right) {
            right--;
            if (left == right) break;
            if (*left != *right) return false;
            left++;
        }

        return true;
    }
};