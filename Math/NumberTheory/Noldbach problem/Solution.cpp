// Problem Link : https://codeforces.com/problemset/problem/17/A
#include <bits/stdc++.h>
using namespace std;

int nextPrime(int v, int n, vector<bool> &isPrime)
{
    for (int x = v; x <= n; x++)
    {
        if (isPrime[x])
            return x;
    }
    return 0;
}


int main()
{
    
    int n, k;
    cin >> n >> k;
    
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            isPrime[j] = false;
        }
    }
    
    vector<int> primes;
    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            primes.push_back(i);

    int c = 0;

    for (int i = 0; i < primes.size() - 1; i++)
    {
        int sum = primes[i] + primes[i + 1] + 1;
        if (sum <= n && isPrime[sum]) c++;
    }

    if (c >= k)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
