// Problem Link : https://www.codechef.com/problems/STRNO
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        ll x, k;
        cin >> x >> k;

        ll ans = 0;

        for (int i = 2; i * i <= x; i++)
        {
            while (x % i == 0)
            {
                ans++;
                x /= i;
            }
        }

        if (x > 1)
            ans++;

        if (ans >= k)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    return 0;
}
