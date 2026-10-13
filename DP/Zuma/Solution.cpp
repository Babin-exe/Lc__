// Problem Link : https://codeforces.com/contest/607/problem/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[501][501];

int solver(int l, int r, vector<int> &v)
{
    if (l > r) return 0;
    if (l == r)return 1;
    if (r - l == 1 && v[l] == v[r]) return 1;
    if (dp[l][r] != -1) return dp[l][r];

    int ans = 1e9;

    for (int k = l; k < r; k++)
    {
        ans = min(ans, solver(l, k, v) + solver(k + 1, r, v));
    }

    if (v[l] == v[r])
    {
        ans = min(ans, solver(l + 1, r - 1, v));
    }

    return dp[l][r] = ans;
}

void solve()
{

    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    vector<int> v(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    cout << solver(0, n - 1, v) << "\n";
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
};
