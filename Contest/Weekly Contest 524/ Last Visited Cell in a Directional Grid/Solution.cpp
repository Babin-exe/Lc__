// Problem Link : https://leetcode.com/problems/last-visited-cell-in-a-directional-grid/
class Solution {
public:
    int l = 0, r = 0;
    int m, n;
    pair<int, int> solve(int i, int j, vector<vector<char>>& grid,
                         vector<vector<bool>>& visited) {

        if (i >= m || j >= n || i < 0 || j < 0)
            return {l, r};

        if (visited[i][j])
            return {l, r};

        l = i, r = j;
        visited[i][j] = true;

        char ch = grid[i][j];

        if (ch == 'R') {
            return solve(i, j + 1, grid, visited);
        } else if (ch == 'L') {
            return solve(i, j - 1, grid, visited);
        } else if (ch == 'U') {
            return solve(i - 1, j, grid, visited);
        } else {
            return solve(i + 1, j, grid, visited);
        }
    }
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m + 1, vector<bool>(n + 1, false));

        pair<int, int> ans = solve(0, 0, grid, visited);
        return {ans.first, ans.second};
    }
};
