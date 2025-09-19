#include <array>
#include <string>
using std::string;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*
learnt[i] = sum(learnt[j], i - forget < j <= i - delay)
*/



class Solution {
public:

    std::array<int, 1000> learner_count {};

    int at(int n, int delay, int forget) {
        if (learner_count[n] != -1) return learner_count[n];
        learner_count[n] = 0;
        for (int i = std::max(n - forget + 1, 0); i <= n - delay; i++) 
            learner_count[n] = (learner_count[n] + at(i, delay, forget)) % 1000000007;
        return learner_count[n];
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        for (int &c : learner_count) {
            c = -1;
        }
        learner_count[0] = 1;
        for (int i = 1; i < delay; i++) 
            learner_count[i] = 0;
        int s = 0;
        for (int i = n - forget; i < n; i++) 
            s = (s + at(i, delay, forget)) % 1000000007;
        return s;
    }   
};