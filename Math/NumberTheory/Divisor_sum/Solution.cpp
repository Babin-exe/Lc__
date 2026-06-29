// Problem Link : https://www.spoj.com/problems/DIVSUM/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{

    /*

    1st approach   -> O(n log(n) )

    vector<ll> sum(500001, 1);

    sum[0] = sum[1] = 0;

    for (int i = 2; i <= 500000; i++)
    {
        for (int j = 2 * i; j <= 500000; j += i)
        {
            sum[j] += i;
        }
    }

    */

    /*
    2nd Approach 
    */

    vector<ll> primes(500001, 0);

    for (int i = 2; i <= 500000; i++)
    {

        if (primes[i] == 0)
        {

            for (int j = i; j <= 500000; j += i)
            {
                if (primes[j] == 0)
                    primes[j] = i;
            }
        }
    }

    ll n;
    cin >> n;
    while (n--)
    {

        ll x;
        cin >> x;

        ll sub = x;

        ll ans = 1;

        while (primes[x] != 0)
        {

            ll c = 1;
            ll t = primes[x];

            while (x % t == 0)
            {
                c++;
                x /= t;
            }

            ll p = 1;
            for (int i = 0; i < c; i++)
                p *= t;
            ans *= ((p - 1) / (t - 1));
        }

        cout << ans - sub << "\n";
    }

    return 0;
}
