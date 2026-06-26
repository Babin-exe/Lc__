// Problem Link : https://codeforces.com/problemset/problem/550/C

#include <bits/stdc++.h>
using namespace std;
int main()
{

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string x;
    cin >> x;


    for (auto &it : x)
    {
        if (it == '0' || it == '8')
        {
            cout << "YES" << "\n";
            cout << it << "\n";
            return 0;
        }
    }

    int i, j, k;
    for (i = 0; i < x.length(); i++)
    {
        for (j = i + 1; j < x.length(); j++)
        {

            long long sum = (x[i] - '0') * 10 + (x[j] - '0');
            if (sum % 8 == 0)
            {
                cout << "YES" << "\n";
                cout << sum << "\n";
                return 0;
            }
        }
    }


    for (i = 0; i < x.length(); i++)
    {
        for (j = i + 1; j < x.length(); j++)
        {

            for (k = j + 1; k < x.length(); k++)
            {

                long long sum = (x[i] - '0') * 100 + (x[j] - '0') * 10 + (x[k] - '0');
                if (sum % 8 == 0)
                {
                    cout << "YES" << "\n";
                    cout << sum << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "NO" << "\n";
    return 0;
}
