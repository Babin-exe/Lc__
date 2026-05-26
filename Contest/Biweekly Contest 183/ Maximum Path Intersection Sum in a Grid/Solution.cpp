// Problem Link : https://leetcode.com/problems/maximum-path-intersection-sum-in-a-grid/
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MIN;
        for (int i = 0; i < m; i++) {

            if (i == 0 || i == m - 1) {
                int curr = grid[i][0] + grid[i][1];
                int gl = curr;
                for (int j = 2; j < n; j++) {
                    curr = max(curr + grid[i][j], grid[i][j] + grid[i][j - 1]);
                    gl = max(gl, curr);
                }
                ans = max(ans, gl);

            } else {

                int curr = max(0, grid[i][0]);

                for (int j = 1; j < n; j++) {
                    if (j != n - 1) {
                        curr = max(grid[i][j] + curr, grid[i][j]);
                    } else {
                        curr =
                            max(curr + grid[i][j], grid[i][j] + grid[i][j - 1]);
                    }
                    ans = max(ans, curr);
                }
            }
        }

        for (int j = 0; j < n; j++) {
            if (j == 0 || j == n - 1) {

                int curr = grid[0][j] + grid[1][j];
                int gl = curr;

                for (int i = 2; i < m; i++) {
                    curr = max(curr + grid[i][j], grid[i][j] + grid[i - 1][j]);
                    gl = max(curr, gl);
                }
                ans = max(ans, gl);

            } else {
                int curr = max(0, grid[0][j]);
                for (int i = 1; i < m; i++) {
                    if (i != m - 1) {
                        curr = max(curr + grid[i][j], grid[i][j]);
                    } else {

                        curr =
                            max(curr + grid[i][j], grid[i][j] + grid[i - 1][j]);
                    }
                    ans = max(ans, curr);
                }
            }
        }

        return ans;
    }
};
