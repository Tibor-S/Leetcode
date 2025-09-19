#include <algorithm>
#include <cstdint>
#include <functional>
#include <queue>
#include <string>
#include <vector>
using std::vector;
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int n2 = 2 * n;
        int n3 = nums.size();
        std::priority_queue<int, vector<int>, std::less<int>> max_heap;
        std::priority_queue<int, vector<int>, std::greater<int>> min_heap;
        long long min_sum = 0;
        long long max_sum = 0;
        std::vector<long long> opt_min(n + 1);
        std::vector<long long> opt_max(n + 1);

        int l = 0;
        int r = n3 - 1;
        for (; l < n; l++, r--) {
            min_sum += nums[l];
            max_sum += nums[r];
            max_heap.push(nums[l]);
            min_heap.push(nums[r]);
        }

        opt_min[0] = min_sum;
        opt_max[n] = max_sum;

        for (; l < n2; l++, r--) {
            if (nums[l] < max_heap.top()) {
                min_sum += nums[l] - max_heap.top();
                max_heap.pop();
                max_heap.push(nums[l]);
            }

            if (nums[r] > min_heap.top()) {
                max_sum += nums[r] - min_heap.top();
                min_heap.pop();
                min_heap.push(nums[r]);
            }

            opt_min[l - n + 1] = min_sum;
            opt_max[r - n] = max_sum;
        }

        long long mn = INT64_MAX;
        for (int i = 0; i <= n; i++) {
            mn = std::min(opt_min[i] - opt_max[i], mn);
        } 

        return mn;
    }
};