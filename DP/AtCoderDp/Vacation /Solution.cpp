// Problem Link : https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> dp;

int solver(int i, int prev, vector<vector<int>> &v)
{
    if (i == n)
        return 0;
    if (i > n)
        return -1e9;

    if (prev != -1)
    {
        if (dp[i][prev] != -1)
            return dp[i][prev];
    }

    int maxi = 0;

    for (int k = 0; k < 3; k++)
    {
        if (k != prev)
        {
            int gain = v[i][k];
            maxi = max(maxi, gain + solver(i + 1, k, v));
        }
    }

    if (prev != -1)
    {
        return dp[i][prev] = maxi;
    }
    else
        return maxi;
}

int solve()
{

    cin >> n;

    dp.assign(n + 1, vector<int>(3, -1));

    vector<vector<int>> v(n, vector<int>(3, 0));

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i][0], cin >> v[i][1], cin >> v[i][2];
    }

    return solver(0, -1, v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        cout << solve() << "\n";
    }

    return 0;
}
