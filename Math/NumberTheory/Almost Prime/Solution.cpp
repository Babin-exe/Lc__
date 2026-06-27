// Problem Link : https://codeforces.com/problemset/problem/26/A
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main()
{

    int n;
    cin >> n;

    vector<int> primes(n + 1, 0);

    for (int i = 2; i <= n; i++)
    {
        if (primes[i] == 0)
        {
            for (int j = i; j <= n; j += i)
            {
                primes[j]++;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++)
        if (primes[i] == 2)
            ans++;

    cout << ans << "\n";
    return 0;
}
