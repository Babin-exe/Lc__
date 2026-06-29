// Problem Link : https://cses.fi/problemset/task/1081
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> vt(n);

    for (int i = 0; i < n; i++)
        cin >> vt[i];

    int maxi = *max_element(begin(vt), end(vt));
    vector<int> sv(maxi + 1, 0);

    for (int i = 0; i < n; i++)
        sv[vt[i]]++;

    for (int i = maxi; i > 0; i--)
    {
        int ans = 0;
        for (int j = i; j <= maxi; j += i)
        {
            if (sv[j] >= 1)
            {
                ans += sv[j];
            }

            if (ans >= 2)
            {
                cout << i << "\n";
                return 0;
            }
        }
    }

    return 0;
}
