// Problem Link : https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/?envType=daily-question&envId=2026-07-01
class Solution {
public:
    int n;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool possible(vector<vector<int>>& dist, int mid) {

        if (dist[0][0] < mid) return false;
        
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        que.push({0, 0});
        visited[0][0] = true;

        while (!que.empty()) {

            auto [r, c] = que.front();
            que.pop();

            if (r == n - 1 && c == n - 1)
                return true;

            for (vector<int>& d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n ||
                    dist[nr][nc] < mid || visited[nr][nc]) {
                    continue;
                }

                visited[nr][nc] = true;
                que.push({nr, nc});
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return 0;

        vector<vector<int>> dist(n, vector<int>(n, -1));
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<pair<int, int>> que;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    que.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int level = 0;
        while (!que.empty()) {

            int size = que.size();

            while (size--) {

                auto [r, c] = que.front();
                que.pop();
                dist[r][c] = level;

                for (vector<int>& d : dir) {

                    int nr = d[0] + r;
                    int nc = d[1] + c;

                    if (nr < 0 || nr >= n || nc < 0 || nc >= n ||
                        visited[nr][nc]) {
                        continue;
                    }

                    visited[nr][nc] = true;
                    que.push({nr, nc});
                }
            }
            level++;
        }

        int ans = 0;
        int l = 0, r = 400;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (possible(dist, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};
