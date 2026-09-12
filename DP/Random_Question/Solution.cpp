/*
You are given n items. Each item requires t[i] units of time and gives s[i] points. 
You have at most x total time and may choose at most k items. Each item can be chosen at most once.

Find the maximum total score you can obtain.

Input:
T — number of test cases.
For each test case:
n x k
t[0] s[0]
t[1] s[1]
...
t[n-1] s[n-1]

Constraints:
1 ≤ T ≤ 100
1 ≤ n ≤ 100
1 ≤ x ≤ 99
1 ≤ k ≤ 99
1 ≤ t[i] ≤ 100
0 ≤ s[i] ≤ 10^9

Output:
For each test case, print the maximum achievable total score.
  */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1000000007;
// const int MOD = 998244353;

ll gcd(ll a, ll b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

ll modpow(ll a, ll b, ll mod = MOD)
{
    ll res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

bool isPrime(ll n)
{
    if (n < 2)
        return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

// sort(all(v));
// sort(rall(v));
// reverse(all(v));
// auto mx = *max_element(all(v));
// auto mn = *min_element(all(v));
// lower_bound(all(v), x);
// upper_bound(all(v), x);
// accumulate(all(v), 0LL);
// __builtin_popcount(x);
// __builtin_popcountll(x);
// __builtin_ctz(x);
// __builtin_clz(x);
// __builtin_parity(x);

int n, x, k;
int dp[100][100][100];
int t[1001], s[1001];

int rec(int level, int time_taken, int item_taken)
{

    if (level == n)
        return 0;

    if (dp[level][time_taken][item_taken] != -1)
        return dp[level][time_taken][item_taken];

    int ans = rec(level + 1, time_taken, item_taken);

    if (time_taken + t[level] <= x && item_taken + 1 <= k)
    {
        ans = max(ans, s[level] + rec(level + 1, time_taken + t[level], item_taken + 1));
    }

    return dp[level][time_taken][item_taken] = ans;
}

void solve()
{
    cin >> n >> x >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> t[i] >> s[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << rec(0, 0, 0) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}
