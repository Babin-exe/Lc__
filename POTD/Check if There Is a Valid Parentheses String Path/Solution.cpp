// Problem Link : https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/description/
/*
Rules :

Solutions are simple.....
observations are simple......
implementation is simple....
 */

/*

Observation :

simple dp , nothing to think much

just that if we have x opening brackets we can have at max x closing only ,,,

if i have 5 closing but anything less than 5 makes us reach invalid state directly..




 */

class Solution {
public:
    int n, m;
    int dp[101][101][202];

    bool solve(int i, int j, int b, vector<vector<char>>& grid) {

        if (b < 0)
            return false;
        if (i == n - 1 && j == m - 1)
            return b == 0;
        if (dp[i][j][b] != -1)
            return dp[i][j][b];

        bool right = false;
        bool down = false;

        if (i < n && j + 1 < m) {
            if (grid[i][j + 1] == '(')
                right = right || solve(i, j + 1, b + 1, grid);
            else
                right = right || solve(i, j + 1, b - 1, grid);
        }

        if (j < m && i + 1 < n) {

            if (grid[i + 1][j] == '(')
                down = down || solve(i + 1, j, b + 1, grid);
            else
                down = down || solve(i + 1, j, b - 1, grid);
        }

        return dp[i][j][b] = right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        if ((n + m - 1) % 2) return false;
        if (grid[0][0] == ')')
            return false;
        if (grid[n - 1][m - 1] == '(')
            return false;
        return solve(0, 0, 1, grid);
    }
};
