// Problem Link : https://codeforces.com/contest/217/problem/B
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

bool canReach(int a, int b, int n)
{
    while (a && b)
    {

        if (a >= b)
        {
            int q = a / b;
            n -= q;
            a %= b;
        }
        else
        {
            int q = b / a;
            if (b % a == 0)
            {
                q--;
            }
            n -= q;
            b -= a * q;
        }
    }

    return min(a, b) == 0 && max(a, b) == 1 && n == 0;
}

string buildString(int a, int b)
{
    if (a == 0 && b == 1)
        return "";
    if (a >= b)
        return buildString(a - b, b) + "T";
    else
        return buildString(a, b - a) + "B";
}

int countMistake(string &s)
{
    int m = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] == s[i])
            m++;
    }
    return m;
}

void solve()
{

    ll n, r;
    cin >> n >> r;

    pair<int, string> result{n + 1, ""};

    for (ll i = 1; i <= r; i++)
    {
        if (canReach(i, r, n))
        {
            string s = buildString(i, r);
            int mistakes = countMistake(s);

            if (mistakes < result.first)
            {
                result = {mistakes, s};
            }
        }

        if (canReach(r, i, n))
        {

            string s = buildString(r, i);
            int mistakes = countMistake(s);

            if (mistakes < result.first)
            {
                result = {mistakes, s};
            }
        }
    }

    if (result.first > n)
    {
        cout << "IMPOSSIBLE" << "\n";
    }
    else
    {
        cout << result.first << "\n" << result.second << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int T = 1;
    // cin >> T;

    // while (T--){
    solve();
    // }

    return 0;
}
