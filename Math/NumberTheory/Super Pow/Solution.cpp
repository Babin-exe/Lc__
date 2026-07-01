// Problem Link : https://leetcode.com/problems/super-pow/description/
const int MOD = 1337;
const int phi = 1140;
using ll = long long;
class Solution {
public:
    ll binpow(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        if (a == 1)
            return 1;

        int expo = 0;
        for (auto& digit : b) {
            expo = (expo * 10 + digit) % phi;
        }

        if (expo == 0) {
            expo = phi;
        }

        return binpow(a, expo) % MOD;
    }
};
