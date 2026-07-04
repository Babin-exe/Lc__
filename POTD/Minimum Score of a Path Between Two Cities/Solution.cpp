// Problem Link : https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/?envType=daily-question&envId=2026-07-04

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> adj(n + 1);
        for (vector<int>& r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<bool> vis(n + 1, false);
        queue<int> que;
        que.push(1);
        vis[1] = true;

        int mini = INT_MAX;
        while (!que.empty()) {

            int u = que.front();
            que.pop();

            for (auto [v, w] : adj[u]) {
                mini = min(mini, w);

                if (!vis[v]) {
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
        return mini;
    }
};
