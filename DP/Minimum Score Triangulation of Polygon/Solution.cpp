// Problem Link : https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& values) {
        if (j - i < 2) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        for (int k = i + 1; k < j; k++) {
            int area = values[i] * values[j] * values[k];
            int ls = solve(i, k, values);
            int rs = solve(k, j, values);

            mini = min(mini, area + ls + rs);
        }
        return dp[i][j] = mini;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return solve(0, n - 1, values);
    }
};
