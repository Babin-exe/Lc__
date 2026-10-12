// Problem Link : https://leetcode.com/problems/maximal-square/description/
class Solution {
public:
    int n;
    int m;

    int solve(int i, int j, vector<vector<char>>& matrix) {
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));


        for (int i = 0; i < m; ++i) {
            dp[0][i] = matrix[0][i] == '1' ? 1 : 0;
            if (dp[0][i] == 1)
                ans = 1;
        }


        for (int i = 1; i < n; ++i) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            if (dp[i][0] == 1)
                ans = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {

                int a = dp[i - 1][j];
                int b = dp[i][j - 1];
                int c = dp[i - 1][j - 1];

                int current = matrix[i][j] == '1' ? 1 : 0;
                if (current == 1) {

                    int mini = min({a, b, c});
                    dp[i][j] = mini + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans == 1 ? 1 : ans * ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        return solve(0, 0, matrix);
    }
};
