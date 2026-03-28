// Problem Link : https://leetcode.com/problems/direction-assignments-with-exactly-k-visible-people/description/

using ll = long long;

class Solution {
    static const ll MOD = 1e9 + 7;
    ll power(ll base, ll exp, ll mod) {
        ll r = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1)
                r = r * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return r;
    }

    ll nCr(int n, int r) {

        if (r < 0 || r > n)
            return 0;

        if (r == 0)
            return 1;

        ll num = 1, den = 1;
        for (int i = 0; i < r; i++) {
            num = num * ((n - i) % MOD) % MOD;
            den = den * ((i + 1) % MOD) % MOD;
        }

        return num * power(den, MOD - 2, MOD) % MOD;
    }

public:
    int countVisiblePeople(int n, int pos, int k) {

        return 2LL * nCr(n - 1, k) % MOD;
    }
};
