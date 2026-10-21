// Problem Link : https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
vector<int> dp;

int solver(int i, vector<int> &v)
{

    if (i == n - 1)
        return 0;

    if (i >= n)
        return 1e9;

    if (dp[i] != -1)
        return dp[i];

    int mini = 1e9;

    for (int a = i + 1; a <= i + k && a < n; a++)
    {

        int jump_cost = abs(v[i] - v[a]);
        mini = min(mini, jump_cost + solver(a, v));
    }

    return dp[i] = mini;
}

int solve()
{

    cin >> n >> k;
    dp.assign(n + 1, -1);

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    return solver(0, v);
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
