
/*
Time complexity understanding : https://en.wikipedia.org/wiki/Divergence_of_the_sum_of_the_reciprocals_of_the_primes
O(n log log n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{

    int n;
    cin >> n;
    vector<bool> primes(n + 1, true);

    primes[0] = false;
    primes[1] = false;

    for (ll i = 2; (ll)i * i <= n; i++)
    {
        if (primes[i] == true)
        {

            for (ll j = i * i; j <= n; j += i)
            {
                primes[j] = false;
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        if (primes[i] == true)
        {
            cout << i << " ";
        }
    }

    return 0;
}
