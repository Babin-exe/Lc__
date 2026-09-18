#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const int MOD = 1e9 + 7;
ll n, m, k;

int dp[2005][2005];

int rec(int level, int bp)
{

    if (bp > k) return 0;

    if (level == n)
        return bp == k;

    if (dp[level][bp] != -1)
        return dp[level][bp];

    int extend = 1 * rec(level + 1, bp) % MOD;
    int new_block = ((m - 1) * rec(level + 1, bp + 1)) % MOD;

    return dp[level][bp] = (extend + new_block) % MOD;
}

void solve()
{

    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));

    cout << (m % MOD) * (rec(1, 0) % MOD) << "\n";
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
