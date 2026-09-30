#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[100001][5];
int n;
string t = "0100";
const int MOD = 1e9 + 7;

ll rec(int level, int pref)
{
    if (pref == 4)
        return 0;

    if (level == n)
        return 1;

    if (dp[level][pref] != -1)
        return dp[level][pref];

    ll ans = (rec(level + 1, pref + 1) % MOD + rec(level + 1, pref) % MOD) % MOD;

    return dp[level][pref] = ans;
}
void solve()
{
    cin >> n;
    cout << rec(0, 0) << "\n";
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        solve();
    }
    return 0;
}
