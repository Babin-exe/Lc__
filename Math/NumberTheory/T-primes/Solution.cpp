// Problem Link : https://codeforces.com/problemset/problem/230/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    const int MAX = 1e6;
    vector<bool> primes(MAX + 1, true);

    primes[0] = primes[1] = false;

    for (int i = 4; i <= MAX; i += 2)
    {
        primes[i] = false;
    }

    for (int i = 3; i * i <= MAX; i += 2)
    {
        if (primes[i])
        {

            for (int j = i * i; j <= MAX; j += 2 * i)
            {
                primes[j] = false;
            }
        }
    }

    int n;
    cin >> n;
    vector<ll> ans(n);

    for (int i = 0; i < n; i++)
        cin >> ans[i];

    for (int i = 0; i < n; i++)
    {
        ll sq = sqrtl(ans[i]);

        if (sq * sq == ans[i] && primes[sq])
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }

    return 0;
}

/*




what do we know ... the total number of factors of a number is just

p^x * p ^y * p ^ k .....


and the number of factors is given as (x+1) * (y+1) * (k+1) so here to get 3 we just need one of the exponent to be

2 and other to be 0  so we just want a prime with power of 2 ,,,,, so that means if we do

sqrt(number) and see if that is a prime we can conclude it has exactly t divisors

and the max here is 10 ^12 so sqrt(10^12) is 10 ^ 6

also the sqrt(num) must be perfect square right.. not a roundoffed one





*/
