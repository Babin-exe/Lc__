// Problem Link : https://cses.fi/problemset/task/1713

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> primes(1000001, 0);

    for (int i = 2; i <= 1000000; i += 2)
        primes[i] = 2;

    for (int i = 3; i * i <= 1000000; i += 2)
    {
        if (primes[i] == 0)
        {
            primes[i] = i;
            for (int j = i * i; j <= 1000000; j += 2 * i)
            {
                if (primes[j] == 0)
                    primes[j] = i;
            }
        }
    }
    for (int i = 2; i <= 1000000; i++)
    {
        if (primes[i] == 0)
            primes[i] = i;
    }

    int n;
    cin >> n;
    while (n--)
    {

        int x;
        cin >> x;

        ll ans = 1;
        while (primes[x] != 0)
        {

            ll t = 1;
            ll s = primes[x];

            while (x % s == 0)
            {
                t++;
                x /= s;
            }

            ans *= t;
        }

        cout << ans << "\n";
    }

    return 0;
}
