// Problem Link :  https://codeforces.com/problemset/problem/682/A

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<ll> a(5, n / 5);
    vector<ll> b(5, m / 5);

    for (int i = 1; i <= n % 5; i++)
        a[i]++;
    for (int i = 1; i <= m % 5; i++)
        b[i]++;

    ll ans = a[0] * b[0];
    for (int i = 1; i < 5; i++)
    {
        ll idx = 5 - i;
        ans += (a[i] * b[idx]);
    }

    cout << ans << "\n";
    return 0;
}
