// Video Link : https://www.youtube.com/watch?v=dFV0gbIdGAU&list=PLqf9emQRQrnKA_EeveiXQj_uP25w8_5qL&index=8

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> x;
int dp[1000][1000];
int n;

int rec(int level, int sum_rem)
{
    if (sum_rem < 0) return 0;
    if (level >= n) return sum_rem == 0;

    if (dp[level][sum_rem] != -1)
        return dp[level][sum_rem];

    int take = rec(level + 1, sum_rem - x[level]);
    int ntake = rec(level + 1, sum_rem);

    int ans = take || ntake;
    return dp[level][sum_rem] = ans;
}

void printset(int level, int rem_sum)
{
    if (level >= n)
        return;

    if (rec(level + 1, rem_sum - x[level]))
    {
        cout << x[level] << "\n";
        printset(level + 1, rem_sum - x[level]);
    }
    else
    {
        printset(level + 1, rem_sum);
    }
}

void solve()
{

    cin >> n;
    ll k;
    x.resize(n);

    for (ll i = 0; i < n; ++i)
    {
        cin >> k;
        x[i] = k;
    }

    memset(dp, -1, sizeof(dp));
    ll q;
    cin >> q;

    while (q--)
    {

        int sum;
        cin >> sum;

        if (rec(0, sum))
        {
            printset(0, sum);
        }
        else
        {
            cout << "Sum not possible" << '\n';
        }
    }
}

int main()
{

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}


// Problem Link : https://maang.in/problems/Subset-Sum-Queries-760

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {


    int n = arr.size();
    int maxSum = *max_element(queries.begin(), queries.end());

    vector<vector<int>> dp(n + 1, vector<int>(maxSum + 1, -1));

    function<int(int, int)> rec = [&](int level, int rem) -> int {

        if (rem < 0)
            return 0;

        if (level == n)
            return rem == 0;

        if (dp[level][rem] != -1)
            return dp[level][rem];

        int take = rec(level + 1, rem - arr[level]);
        int ntake = rec(level + 1, rem);

        return dp[level][rem] = take || ntake;
    };

    vector<vector<int>> ans;

    for (int query : queries) {

        if (!rec(0, query)) {
            ans.push_back({-1});
            continue;
        }

        vector<int> indices;

        int level = 0;
        int rem = query;

        while (level < n && rem > 0) {

            if (rec(level + 1, rem - arr[level])) {
                indices.push_back(level);
                rem -= arr[level];
            }

            level++;
        }

        ans.push_back(indices);
    }

    return ans;

}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        long long sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}

