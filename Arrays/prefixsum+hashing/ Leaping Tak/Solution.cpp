// Problem Link : https://atcoder.jp/contests/abc179/tasks/abc179_d
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> seg(K);

    for (int i = 0; i < K; i++)
    {
        cin >> seg[i].first >> seg[i].second;
    }

    vector<ll> dp(N + 1, 0);
    vector<ll> pref(N + 1, 0);

    dp[1] = 1;
    pref[1] = 1;

    for (int i = 2; i <= N; i++)
    {

        for (auto [L, R] : seg)
        {

            int left = max(1, i - R);
            int right = i - L;

            if (right < 1)
                continue;

            dp[i] += pref[right];

            if (left > 1)
                dp[i] -= pref[left - 1];

            dp[i] %= MOD;

            if (dp[i] < 0)
                dp[i] += MOD;
        }

        pref[i] = (pref[i - 1] + dp[i]) % MOD;
    }

    cout << dp[N] << '\n';
}
