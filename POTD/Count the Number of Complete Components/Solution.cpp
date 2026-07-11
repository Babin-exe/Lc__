// Problem Link : https://leetcode.com/problems/count-the-number-of-complete-components/description/?envType=daily-question&envId=2026-07-11
class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited, int& e,
             int& v) {

        v++;
        visited[i] = true;
        e += adj[i].size();

        for (auto& a : adj[i]) {
            if (visited[a] == true) {
                continue;
            }
            dfs(a, adj, visited, e, v);
        }
    };

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;

        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i] == true)
                continue;

            int e = 0;
            int v = 0;

            dfs(i, adj, visited, e, v);

            if (v * (v - 1) == e)
                ans++;
        }

        return ans;
    }
};
