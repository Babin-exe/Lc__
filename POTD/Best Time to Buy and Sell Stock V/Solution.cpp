// Problem Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/description/

class Solution {
public:
    long long dp[1001][501][3];
    long long solve(int i, int k, int Case, vector<int>& prices) {
        if (i >= prices.size()) {
            if (Case == 0)
                return 0;
            return INT_MIN;
        }

        if (dp[i][k][Case] != INT_MIN)
            return dp[i][k][Case];

        long long take = INT_MIN;
        long long dont = solve(i + 1, k, Case, prices);
        if (k > 0) {

            if (Case == 1) { // sell
                take = prices[i] + solve(i + 1, k - 1, 0, prices);
            } else if (Case == 2) { // buy
                take = -prices[i] + solve(i + 1, k - 1, 0, prices);
            } else { // buy or sell not final
                take = max(-prices[i] + solve(i + 1, k, 1, prices),
                           prices[i] + solve(i + 1, k, 2, prices));
            }
        }
        return dp[i][k][Case] = max(take, dont);
    }

    long long maximumProfit(vector<int>& prices, int k) {
        for (int i = 0; i < prices.size(); i++) {
            for (int j = 0; j <= k; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = INT_MIN;
                }
            }
        }

        return solve(0, k, 0, prices);
    }
};
