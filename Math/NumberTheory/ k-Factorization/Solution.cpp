// Problem Link : https://codeforces.com/problemset/problem/797/A
#include <bits/stdc++.h>
using namespace std;
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;
    long long temp = n;

    vector<long long> vt;

    for (int i = 2; i * i <= temp; i++)
    {
        while (temp % i == 0)
        {
            vt.push_back(i);
            temp /= i;
        }
    }
    if (temp > 1)
        vt.push_back(temp);

    if ((int)vt.size() < k)
    {
        cout << -1 << "\n";
    }
    else
    {

        vector<long long> ans;
        for (int i = 0; i < k - 1; i++)
        {
            ans.push_back(vt[i]);
        }

        long long prod = 1;
        for (int i = k - 1; i < (int)vt.size(); i++)
        {
            prod *= vt[i];
        }
        ans.push_back(prod);

        for (int i = 0; i < (int)ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
