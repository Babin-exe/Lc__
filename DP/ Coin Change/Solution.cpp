// Problem Link : https://leetcode.com/problems/coin-change/description/
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
