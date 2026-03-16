// Problem Link : https://leetcode.com/problems/count-fancy-numbers-in-a-range/description/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    string s;
    ll dp[18][150][11][2][2][2][2];
    bool goodsum[150];
    bool goodSum(int x) {
        string s = to_string(x);
        bool inc = true, dec = true;

        for (int i = 1; i < (int)s.size(); i++) {
            if (s[i] <= s[i - 1])
                inc = false;
            if (s[i] >= s[i - 1])
                dec = false;
        }
        return inc || dec;
    }

    ll dp_func(int pos, int sum, int prev, bool tight, bool started, bool inc,
               bool dec) {

        if (pos == (int)s.size()) {
            if (!started)
                return 0;

            return (inc || dec || goodsum[sum]);
        }

        ll& res = dp[pos][sum][prev][tight][started][inc][dec];
        if (res != -1)
            return res;

        res = 0;
        int limit = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started && d == 0) {

                res += dp_func(pos + 1, sum, 10, ntight, 0, 1, 1);
            } else {
                bool ninc = inc;
                bool ndec = dec;

                if (started) {
                    if (d <= prev)
                        ninc = false;
                    if (d >= prev)
                        ndec = false;
                }

                res += dp_func(pos + 1, sum + d, d, ntight, 1, ninc, ndec);
            }
        }

        return res;
    }

    ll solve(ll x) {
        s = to_string(x);
        memset(dp, -1, sizeof(dp));
        return dp_func(0, 0, 0, 1, 0, 1, 1);
    }

    ll countFancy(ll l, ll r) {
        for (int i = 0; i < 150; i++)
            goodsum[i] = goodSum(i);
        return solve(r) - solve(l - 1);
    }
};
