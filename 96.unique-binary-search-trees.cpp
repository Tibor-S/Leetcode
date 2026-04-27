/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
#define NV 1
#define NV2 NV, NV
#define NV4 NV2, NV2
#define NV8 NV4, NV4
#define NV16 NV8, NV8
#define NV19 NV16, NV2, NV
#define NC {{NV19}}
class Solution {
public:
    int N;
    int combs[19][19] NC;
    int numTrees(int n) {
        N = n;
        aux(n-1);
        return combs[N-1][0];
    }

    void aux(int n) {
        int len = n + 1;
        if (!n)
            return;
        
        aux(n-1);


        for (int left = 0; left < N-n; left++)
            construct_all(left, len);
    }

    void construct_all(int left, int len) {
        for (int left_len = 0; left_len < len; left_len++)
            construct_some(left, left_len, len);
    }

    void construct_some(int left, int left_len, int len) {
        int right_len = len - left_len - 1;
        int head = left + left_len;
        int right = head + 1;
        if (!right_len) {
            combs[len - 1][left] += combs[left_len - 1][left];
            return;
        }
        if (!left_len) {
            combs[len - 1][left] += combs[right_len - 1][right];
            return;
        }

        combs[len - 1][left] += combs[left_len - 1][left] * combs[right_len - 1][right];
    }
};
// @lc code=end

