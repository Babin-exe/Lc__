// Problem Link : https://codeforces.com/contest/478/problem/D
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int giveH(int r, int g)
{
    return (-1 + sqrt(1 + 8.0 * (r + g))) / 2;
}

int solver(int r, int g, int h)
{
    vector<int> pr(r + 1, 0);
    vector<int> cr(r + 1, 0);

    int ans = 0;

    pr[0] = 1;

    for (int height = 1; height <= h; ++height)
    {
        for (int red = 0; red <= r; ++red)
        {

            // Take green
            cr[red] = pr[red];

            // Take red
            if (red >= height)
            {
                cr[red] += pr[red - height];
            }

            if (cr[red] >= MOD)
                cr[red] -= MOD;
        }

        swap(pr, cr);
    }

    int total = h * (h + 1) / 2;
    for (int red = 0; red <= r; red++)
    {

        if (total - red <= g)
        {
            ans += pr[red];
        }

        if (ans >= MOD)
            ans -= MOD;
    }

    return ans;
}

int solve()
{

    int r, g;
    cin >> r >> g;

    int height = giveH(r, g);

    // int height = (-1 + sqrt(1 + 8.0 * (r + g))) / 2;

    /*

    First of all let me find the best height directly
    but how ???

    lets say that i have ,, Red + Green count = Total

    Now think one thing , if i say  n * (n+1) /2 , this is  sum of natural number

    and here 4 * (4+1) /2 = 10 , matches exactly the total of first test case

    so let say n * (n+1) / 2 = x
    now n ^ 2 + n = 2x or
    n^2 + n - 2x =0

    now i need to solve for n to get the best height first.....

    a = 1
    b = 1
    c = -2x


     -4ac = - 4 * 1 * -2x
     -4ac = 8x

    n = -1 + sqrt(1 + 8x ) / 2


    */

    return solver(r, g, height);
}

int main()
{
    int t = 1;
    // cin >> t;

    while (t--)
    {

        cout << solve() << "\n";
    }
    return 0;
}
