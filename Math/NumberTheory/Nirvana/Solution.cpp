// Problem Link : https://codeforces.com/problemset/problem/1143/B
#include <bits/stdc++.h>
using namespace std;

int giveProd(long long x)
{
    long long t = 1;
    while (x != 0)
    {
        t = t * (x % 10);
        x /= 10;
    }
    return t;
}

int main()
{

    int n;
    cin >> n;
    int p = 1;
    int ans = 0;
    n++;
    while (n != 0)
    {
        ans = max(ans, giveProd(n * p - 1));
        n /= 10;
        p *= 10;
    }

    cout << ans << "\n";

    return 0;
}
