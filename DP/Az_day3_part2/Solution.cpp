// Video Link : https://www.youtube.com/watch?v=dFV0gbIdGAU&list=PLqf9emQRQrnKA_EeveiXQj_uP25w8_5qL&index=8

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> x;
int dp[1000][1000];
int n;

int rec(int level, int sum_rem)
{
    if (sum_rem < 0) return 0;
    if (level >= n) return sum_rem == 0;

    if (dp[level][sum_rem] != -1)
        return dp[level][sum_rem];

    int take = rec(level + 1, sum_rem - x[level]);
    int ntake = rec(level + 1, sum_rem);

    int ans = take || ntake;
    return dp[level][sum_rem] = ans;
}

void printset(int level, int rem_sum)
{
    if (level >= n)
        return;

    if (rec(level + 1, rem_sum - x[level]))
    {
        cout << x[level] << "\n";
        printset(level + 1, rem_sum - x[level]);
    }
    else
    {
        printset(level + 1, rem_sum);
    }
}

void solve()
{

    cin >> n;
    ll k;
    x.resize(n);

    for (ll i = 0; i < n; ++i)
    {
        cin >> k;
        x[i] = k;
    }

    memset(dp, -1, sizeof(dp));
    ll q;
    cin >> q;

    while (q--)
    {

        int sum;
        cin >> sum;

        if (rec(0, sum))
        {
            printset(0, sum);
        }
        else
        {
            cout << "Sum not possible" << '\n';
        }
    }
}

int main()
{

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
