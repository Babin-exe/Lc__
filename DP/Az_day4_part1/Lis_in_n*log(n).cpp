#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> lis;
    vector<int> insertion_at(n);

    for (int i = 0; i < n; ++i)
    {
        if (lis.empty() || lis.back() < arr[i])
        {
            lis.push_back(arr[i]);
            insertion_at[i] = lis.size() - 1;
        }
        else
        {
            auto it = lower_bound(begin(lis), end(lis), arr[i]);
            *it = arr[i];
            insertion_at[i] = it - begin(lis);
        }
    }

    cout << lis.size() << "\n ";

    vector<int> ans;

    int pos = lis.size() - 1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (insertion_at[i] == pos)
        {
            ans.push_back(arr[i]);
            pos--;
        }
    }

    for (int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i] << " ";

    cout << "\n";
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
