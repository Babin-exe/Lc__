// Problem Link : https://leetcode.com/contest/weekly-contest-523/problems/prime-subset-selection-i/
/*
observations :
*/
using ll = long long;

class Solution {

public:
    inline static bool hehe = false;
    inline static vector<int> primes;

    void fillPrimes() {
        hehe = true;
        const int maxi = 1e6 + 1;

        vector<int> spf(maxi, 0);

        for (int i = 2; i < maxi; i++) {
            if (spf[i] == 0) {
                primes.push_back(i);
                spf[i] = i;

                for (ll j = 1LL * i * i; j < maxi; j += i) {
                    if (spf[j] == 0) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    vector<int> maxPrimes(int n, int s) {
        if (!hehe) {
            fillPrimes();
        }

        vector<int> ans;
        int sum = 0;
        for (int i = 0; i < primes.size(); ++i) {
            int val = primes[i];
            if (val > n)
                break;
            if (sum + val > s)
                break;

            ans.push_back(val);
            sum += val;
        }
        return ans;
    }
};
