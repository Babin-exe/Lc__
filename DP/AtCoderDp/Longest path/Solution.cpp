// Problem Link : https://atcoder.jp/contests/dp/tasks/dp_g
#include <bits/stdc++.h>
using namespace std;

int solve(int node, vector<int> &dp, int n, vector<vector<int>> &adj)
{

    if (dp[node] != -1)
        return dp[node];

    int maxi = -1;

    for (auto v : adj[node])
    {
        maxi = max(maxi, 1 + solve(v, dp, n, adj));
    }

    return dp[node] = maxi;
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<int> dp(n + 1, -1);

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (adj[i].size() == 0)
        {
            dp[i] = 0;
        }
    }

    int ans = -1;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, solve(i, dp, n, adj));
    }

    cout << ans << "\n";

    return 0;
}
