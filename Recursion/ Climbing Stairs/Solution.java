// Problem Link : https://leetcode.com/problems/climbing-stairs/

class Solution {
    int[] dp = new int[46];

    public int solve(int n) {
        if (n == 0 || n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n - 1) + solve(n - 2);

    }

    public int climbStairs(int n) {
        for (int i = 0; i < 46; i++) {
            dp[i] = -1;
        }
        return solve(n);
    }
}
