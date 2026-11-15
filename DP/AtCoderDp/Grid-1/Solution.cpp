// Problem Link : https://atcoder.jp/contests/dp/tasks/dp_h
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> dp;
int row, col;

int solve(int i, int j, vector<string> &t)
{

    if (i == row - 1 && j == col - 1)
        return 1;

    if (i == row || j == col)
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int right = 0;
    int down = 0;

    if (j + 1 < col && t[i][j + 1] == '.')
    {
        right += solve(i, j + 1, t) % MOD;
    }

    if (i + 1 < row && t[i + 1][j] == '.')
    {
        down += solve(i + 1, j, t) % MOD;
    }

    return dp[i][j] = (right + down) % MOD;
}

int main()
{

    cin >> row >> col;

    dp.resize(row + 1, vector<int>(col + 1, -1));

    vector<string> t(row + 1);

    for (int i = 0; i < row; ++i)
    {
        cin >> t[i];
    }

    cout << solve(0, 0, t) << "\n";

    return 0;
}
