//Problem Link : https://cses.fi/problemset/task/2220

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[11][20][2][2];

ll dp_func(string &s, ll prev, int idx, bool lz, bool tight)
{
    int n = s.size();

    if (idx == n)
        return 1;

    if (dp[prev][idx][lz][tight] != -1)
        return dp[prev][idx][lz][tight];

    ll ans = 0;

    ll lb = 0;
    ll ub = (tight == true) ? s[idx] - '0' : 9;

    for (ll val = lb; val <= ub; val++)
    {

        if (!lz && prev == val)
            continue;

        ans += dp_func(s, val, idx + 1, (lz && val == 0), (tight && val == ub) ? 1 : 0);
    }

    return dp[prev][idx][lz][tight] = ans;
}

ll solve(ll a, ll b)
{

    string l = to_string(a - 1);
    string r = to_string(b);

    memset(dp, -1, sizeof(dp));

    ll ans_l = dp_func(l, 10, 0, 1, 1);

    memset(dp, -1, sizeof(dp));

    ll ans_r = dp_func(r, 10, 0, 1, 1);

    return ans_r - ans_l;
}

int main()
{

    ll a, b;
    cin >> a >> b;
    cout << solve(a, b);

    return 0;
}



        
