// Problem Link: https://leetcode.com/problems/number-of-zigzag-arrays-i/description/?envType=daily-question&envId=2026-06-24

vector<vector<vector<int>>> dp(2000,
                               vector<vector<int>>(2000, vector<int>(2, 0)));
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int UP = 0, DOWN = 1;
        int m = r - l + 1;

        int ans = 0;
        const int MOD = 1e9 + 7;

        for (int i = 0; i < m; i++) {
            dp[0][i][UP] = 1;
            dp[0][i][DOWN] = 1;
        }

        for (int i = 1; i < n; i++) {
            int psum = 0;
            for (int k = 0; k < m; k++) {
                dp[i][k][UP] = psum;
                psum = (psum + dp[i - 1][k][DOWN]) % MOD;
            }

            int ssum = 0;
            for (int k = m - 1; k >= 0; k--) {
                dp[i][k][DOWN] = ssum;
                ssum = (ssum + dp[i - 1][k][UP]) % MOD;
            }
        }

        long long cur = ans;
        for (int i = 0; i < m; i++) {
            cur += dp[n - 1][i][UP];
            cur += dp[n - 1][i][DOWN];
            ans = cur % MOD;
        }
        return ans;
    }
};
