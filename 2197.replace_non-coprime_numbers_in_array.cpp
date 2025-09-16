#include <algorithm>
#include <cmath>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>
using std::vector;
using std::string;
using std::unordered_map;
using std::optional;
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

6   4   3   2   7   6   2
12  -1  
            











*/      

struct Factor {
    int pi;
    int count;
};

class Solution {
public:

    vector<int> primes = {2,3};
    unordered_map<int, vector<Factor>> prime_factors;

    bool is_prime(int pot) {
        int end = std::distance(
            primes.begin(),
            std::upper_bound(primes.begin(), primes.end(), sqrt(pot)+1));

        for (int pi = 0; pi < end; pi++) {
            if (!(pot % primes[pi])) 
                return false; 
        }
        return true;
    }

    Factor calc_factor(int* n, int pi) {
        Factor f = {pi, 0};
        int prime = primes[pi];
        while (!(*n % prime)) {
            *n /= prime;
            f.count++;
        }

        return f;
    }

    void factorize(int n) {
        if (!prime_factors[n].empty()) return;
        int original = n;

        for (int pi = 0; pi < primes.size() && n > 1; pi++) {
            int prime = primes[pi];
            if (n % prime)
                continue;

            prime_factors[original].push_back(calc_factor(&n, pi));
        }

        for (int prime = primes.back()+2; n > 1; prime += 2) {
            if (!is_prime(prime))
                continue;
            int pi = primes.size();
            primes.push_back(prime);
            if (n % prime)
                continue;

            prime_factors[original].push_back(calc_factor(&n, pi));
        }
    }

    optional<int> lcm(int l, int r) {
        vector<Factor> nfs {};
        auto lit = prime_factors[l].begin();
        auto lend = prime_factors[l].end();
        auto rit = prime_factors[r].begin();
        auto rend = prime_factors[r].end();

        bool coprime = true;
        while (lit != lend && rit != rend) {
            Factor lf = *lit;
            Factor rf = *rit;
            Factor nf;
            if (lf.pi == rf.pi) {
                coprime = false;
                nf = lf.count < rf.count ? rf : lf;
                lit++; rit++;
            } else if (lf.pi < rf.pi) {
                nf = lf;
                lit++;
            } else {
                nf = rf;
                rit++;
            }
            nfs.push_back(nf);
        }
        if (coprime) return {};
        while (lit != lend) 
            nfs.push_back(*(lit++));
        while (rit != rend) 
            nfs.push_back(*(rit++));

        int n = 1;
        for (Factor f : nfs)
            n *= std::pow(primes[f.pi], f.count);

        prime_factors[n] = nfs;
        return n;
    }

    void alter(int prev, vector<int>& nums) {
    }
    
    void check_again(int prev, vector<int>& nums) {
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        for (int n : nums) {
            factorize(n);
        }

        for (int i = nums.size()-2; i >= 0; i--) {
            auto pot_lcm = lcm(nums[i], nums[i+1]);
            while (pot_lcm.has_value() && i < nums.size()-1) {
                nums[i] = pot_lcm.value();
                nums.erase(nums.begin()+i+1);
                pot_lcm = lcm(nums[i], nums[i+1]);
            }
        }

        return nums;
    }
};