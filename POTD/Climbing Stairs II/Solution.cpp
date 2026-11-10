// Problem Link :https://leetcode.com/problems/climbing-stairs-ii/ 

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        if (n == 1)
            return 1 + costs[0];
        if (n == 2)
            return min(4 + costs[1], 2 + costs[0] + costs[1]);

        vector<int> dp(n + 1, 0);

        dp[n - 1] = 1 + costs[n - 1];
        dp[n - 2] = min(1 + costs[n - 2] + dp[n - 1], 4 + costs[n - 1]);

        for (int i = n - 3; i >= 0; --i) {

            int one = 1 + dp[i + 1] + costs[i];
            int two = 4 + dp[i + 2] + costs[i + 1];
            int three = 9 + dp[i + 3] + costs[i + 2];

            dp[i] = min({one, two, three});
        }

        return dp[0];
    }
};
