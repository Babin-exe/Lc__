// Problem Link : https://atcoder.jp/contests/dp/tasks/dp_i
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<double>> dp;

double solve(int i, int head_count, vector<double> &p)
{
    if (i == n)
        return head_count > n / 2 ? 1.0 : 0.0;

    if (dp[i][head_count] != -1.0)
        return dp[i][head_count];

    double head = p[i] * solve(i + 1, head_count + 1, p);
    double tail = (1.0 - p[i]) * solve(i + 1, head_count, p);

    return dp[i][head_count] = head + tail;
}

int main()
{
    cin >> n;

    dp.assign(n + 1, vector<double>(n + 1, -1.0));

    vector<double> p(n);

    for (int i = 0; i < n; ++i)
        cin >> p[i];

    cout << fixed << setprecision(15) << solve(0, 0, p) << '\n';

    return 0;
}
