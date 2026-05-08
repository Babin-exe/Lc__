
// Problem Link : https://codeforces.com/contest/2031/problem/D
 // https://leetcode.com/problems/jump-game-ix/description/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<int> a(n, 0);
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> pm(n, 0);
        vector<int> sm(n, 0);
        pm[0] = a[0];
        sm[n - 1] = a[n - 1];

        for (int i = 1; i < n; i++)
        {
            pm[i] = max(pm[i - 1], a[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            sm[i] = min(sm[i + 1], a[i]);
        }

        ans[n - 1] = pm[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {

            if (pm[i] <= sm[i + 1])
            {
                ans[i] = pm[i];
            }
            else
            {
                ans[i] = ans[i + 1];
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
