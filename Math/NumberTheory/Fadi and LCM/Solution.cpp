// Problem Link : https://codeforces.com/problemset/problem/1285/C
#include <bits/stdc++.h>
using namespace std;
int main()
{

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long long x;
    cin >> x;

    long long mini = LLONG_MAX;
    long long a = -1, b = -1;

    for (long long i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            if (lcm(x / i, i) == x)
            {
                long long maxi = max(i, x / i);
                if (mini > maxi)
                {
                    mini = maxi;
                    a = i, b = x / i;
                }
            }
        }
    }

    cout << a << " " << b << "\n";

    return 0;
}
