// Problem Link : https://leetcode.com/problems/coin-change/description/

//Recursive : 
class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, vector<int>& c, int a) {

        if (a == 0) return 0;

        if (i >= n || a < 0) return 1e8;

        if (dp[i][a] != -1) return dp[i][a];

        int skip = solve(i + 1, c, a);
        int take = 1 + solve(i, c, a - c[i]);

        return dp[i][a] = min(skip, take);
    }

    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        dp.resize(n + 1, vector<int>(amount + 1, -1));

        int ans = solve(0, coins, amount);
        return ans == 1e8 ? -1 : ans;
    }
};


//Iterative : 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 1e8));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int s = 1; s <= amount; ++s) {


                int skip = dp[i + 1][s];

                int take = 1e8;
                if (s >= coins[i] && dp[i][s - coins[i]] != 1e8) {
                    take = 1 + dp[i][s - coins[i]];
                }

                dp[i][s] = min(skip, take);
            }
        }

        return dp[0][amount] == 1e8 ? -1 : dp[0][amount];
    }
};
