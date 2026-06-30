// Problem Link : https://lightoj.com/problem/mathematically-hard

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

// ---------------- Number Theory ----------------

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

// ---------------- Common Tricks ----------------

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

const int MAXI = 5 * 1e6 + 1;
vector<int> t(5 * 1e6 + 1);
vector<ull> p(MAXI + 1);
void precompute()
{

    for (int i = 0; i < MAXI; i++)
        t[i] = i;

    for (int i = 2; i < MAXI; i++)
    {

        if (t[i] == i)
        {
            t[i] = i - 1;
            for (int j = 2 * i; j < MAXI; j += i)
            {
                t[j] = t[j] - (t[j] / i);
            }
        }
    }

    p[0] = 0;
    for (int i = 1; i < MAXI; i++)
    {
        p[i] = 1ULL * t[i] * t[i] + p[i - 1];
    }
}

void solve(int c)
{

    ll a, b;
    cin >> a >> b;

    cout << "Case " << c << ": " << p[b] - p[a - 1] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    precompute();

    int c = 1;
    while (T--)
    {
        solve(c++);
    }

    return 0;
}
