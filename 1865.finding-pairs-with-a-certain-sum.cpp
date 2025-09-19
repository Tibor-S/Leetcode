#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class FindSumPairs {
public:
    vector<int>& n1;
    vector<int>& n2;
    std::unordered_map<int, int> cnt {};

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : n1(nums1), n2(nums2) {
        std::sort(n1.begin(), n1.end());
        for (int n : n2) {
            cnt[n]++;
        }
    }
    
    void add(int index, int val) {
        cnt[n2[index]]--;
        n2[index] += val;
        cnt[n2[index]]++;
    }
    
    int count(int tot) {
        int c = 0;
        for (auto n : n1) {
            c += cnt.contains(tot-n) ? cnt[tot - n] : 0;
        }
        return c;
    }
};
