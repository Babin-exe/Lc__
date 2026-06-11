// Problem Link : https://codeforces.com/problemset/problem/1165/D

#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        sort(begin(v), end(v));
        long long ans = v[0] * v[n - 1];

        vector<long long> vt;

        for (long long i = 2; (long long)i * i <= ans; i++)
        {

            if (ans % i == 0)
            {
                vt.push_back(i);

                if ((ans / i) != i)
                    vt.push_back(ans / i);
            }
        }

        sort(begin(vt), end(vt));

        if (v == vt)
            cout << ans << "\n";
        else
            cout << -1 << "\n";
    }
}
