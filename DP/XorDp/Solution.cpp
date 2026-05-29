/*
You are given an n×n grid of integers.
You must choose exactly one element from each row.
Let the chosen elements be: a0,a1,a2,…,an−1
Your task is to determine whether it is possible to choose the elements such that:

a0 ⊕ a1 ⊕ a2 ⊕ ⋯ ⊕ an−1 = X
where ⊕ denotes the bitwise XOR operation.
x > 0

Input
The first line contains an integer n (1≤n≤100)
The next n lines each contain n integers representing the grid.

 output true if there exists x that is > 0 else false.

*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<vector<int>> &v)
{

    int n = v.size();
    vector<vector<bool>> dp(n, vector<bool>(128, false));

    for (int i = 0; i < n; i++)
        dp[0][v[0][i]] = true;

    for (int i = 1; i < n; i++)
    {

        for (int xr = 0; xr <= 127; xr++)
        {

            for (int j = 0; j < n; j++)
            {
                int curr = v[i][j];

               dp[i][xr] |= dp[i - 1][xr ^ curr];
            }
        }
    }
    for (int i = 1; i <=127; i++)
    {
        if (dp[n - 1][i])
            return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    cout << (isPossible(v) ? "YES" : "NO");

    return 0;
}
