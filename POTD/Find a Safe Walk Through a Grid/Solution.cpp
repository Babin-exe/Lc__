Problem Link : https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> vals(n, vector<int>(m, -1));
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<tuple<int, int, int>> que;

        int start = health - grid[0][0];
        if (start <= 0)
            return false;

        vals[0][0] = start;

        que.push({0, 0, start});
        visited[0][0] = true;

        while (!que.empty()) {

            auto [r, c, h] = que.front();
            que.pop();

            if (r == n - 1 && c == m - 1 && h > 0) {
                return true;
            }

            for (vector<int> d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                int newHealth = h - grid[nr][nc];
                if (newHealth <= 0)
                    continue;

                if (vals[nr][nc] >= newHealth) {
                    continue;
                }

                que.push({nr, nc, newHealth});
                vals[nr][nc] = newHealth;
            }
        }

        return false;
    }
};

