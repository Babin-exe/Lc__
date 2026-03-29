// Problem Link : https://leetcode.com/problems/minimum-xor-path-in-a-grid/

class Solution {
    public int minCost(int[][] grid) {

        int m = grid.length, n = grid[0].length;
        boolean[][][] dp = new boolean[m][n][1024];
        dp[0][0][grid[0][0]] = true;

        for (int j = 1; j < n; j++) {
            for (int v = 0; v < 1024; v++) {
                if (dp[0][j - 1][v])
                    dp[0][j][v ^ grid[0][j]] = true;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int v = 0; v < 1024; v++) {
                if (dp[i-1][0][v])
                    dp[i][0][v ^ grid[i][0]] = true;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int v = 0; v < 1024; v++) {
                    if (dp[i - 1][j][v]) {
                        dp[i][j][v ^ grid[i][j]] = true;
                    }

                    if (dp[i][j - 1][v]) {
                        dp[i][j][v ^ grid[i][j]] = true;
                    }
                }
            }
        }

        for (int i = 0; i < 1024; i++) {
            if (dp[m - 1][n - 1][i])
                return i;
        }
        return -1;
    }
}
