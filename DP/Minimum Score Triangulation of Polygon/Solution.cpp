// Problem Link : https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& values) {
        if (j - i < 2) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        for (int k = i + 1; k < j; k++) {
            int area = values[i] * values[j] * values[k];
            int ls = solve(i, k, values);
            int rs = solve(k, j, values);

            mini = min(mini, area + ls + rs);
        }
        return dp[i][j] = mini;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return solve(0, n - 1, values);
    }
};

// A bit different version of the same question : 
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Point = pair<double, double>;

double triangleCost(Point a, Point b, Point c)
{
    double cross =
        (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);

    return abs(cross) / 2.0;
}

void solve()
{
    int n;
    cin >> n;

    vector<Point> v(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }

    if (n < 3)
    {
        cout << 0 << "\n";
        return;
    }

    vector<vector<double>> dp(
        n + 1, vector<double>(n + 1, 0.0));

    for (int gap = 2; gap < n; ++gap)
    {

        for (int i = 1; i + gap <= n; ++i)
        {
            int j = i + gap;

            dp[i][j] = numeric_limits<double>::infinity();

            for (int k = i + 1; k < j; ++k)
            {

                double candidate =
                    dp[i][k] + dp[k][j] + triangleCost(v[i], v[k], v[j]);

                dp[i][j] = min(dp[i][j], candidate);
            }
        }
    }

    cout << dp[1][n] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
