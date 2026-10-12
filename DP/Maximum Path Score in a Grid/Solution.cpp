// Problem Link : https://leetcode.com/problems/maximum-path-score-in-a-grid/description/
class Solution {
public:
    vector<vector<vector<int>>> dp;

    int n, m;
    int solve(int i, int j, int rem, vector<vector<int>>& grid) {

        if (i >= n || j >= m || rem < 0) return INT_MIN;

        int current_cost = (grid[i][j] == 0 ? 0 : 1);
        int grid_val = grid[i][j];
        int rem_cost = rem - current_cost;

        if (rem < current_cost)
            return INT_MIN;

        if (i == n - 1 && j == m - 1) {
            return grid_val;
        }

        if (dp[i][j][rem] != -1)
            return dp[i][j][rem];

        int temp = -1;

        if (i + 1 < n) {
            temp = max(temp, solve(i + 1, j, rem_cost, grid));
        }

        if (j + 1 < m) {
            temp = max(temp, solve(i, j + 1, rem_cost, grid));
        }

        if (temp == -1) {
            return dp[i][j][rem] = INT_MIN;
        }

        return dp[i][j][rem] = grid_val + temp;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));

        int ans = solve(0, 0, k, grid);
        return ans == INT_MIN ? -1 : ans;
    }
};
