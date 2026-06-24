// Problem Link : https://codeforces.com/problemset/problem/1474/B
#include <bits/stdc++.h>
using namespace std;

int givePrime(int a)
{
    for (int x = a;; x++)
    {
        bool isPrime = true;
        for (int j = 2; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            return x;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;

        int p, q;

        p = givePrime(d + 1);
        q = givePrime(p + d);

        cout << min(1LL * p * q, 1LL * p * p * p) << "\n";
    }
    return 0;
}
