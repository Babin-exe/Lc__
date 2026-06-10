#include <bits/stdc++.h>
using namespace std;

vector<int> findFactors(int x)
{
    vector<int> ans;
    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            ans.push_back(i);
            x /= i;
        }
    }
    if (x > 1)
        ans.push_back(x);

    return ans;
}

int main()
{

    int n;
    cin >> n;
    vector<int> hehe = findFactors(n);

    for (auto &it : hehe)
        cout << it << " ";

    return 0;
}
