// Problem Link:https://leetcode.com/problems/distinct-subsequences-ii/description/
using ll = long long;
const int mod = 1e9 + 7;
class Solution {
public:
    int distinctSubseqII(string s) {

        vector<ll> prev(26, 0);
        int n = s.length();


        vector<ll> dp(n + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            int c = s[i - 1] - 'a';


            ll x = (dp[i - 1] * 2) % mod;

            dp[i] = (x - prev[c] + mod) % mod;
            prev[c] = dp[i - 1];
        }

        return (dp[n] - 1 + mod) % mod;
    }
};
