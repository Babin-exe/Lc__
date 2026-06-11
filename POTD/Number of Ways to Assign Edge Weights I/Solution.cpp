// Problem Link : https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/description/?envType=daily-question&envId=2026-06-11
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj) {
        int ans = 0;
        for (int curr : adj[node]) {
            if (curr == parent)
                continue;
            ans = max(ans, dfs(curr, node, adj));
        }

        return ans + 1;
    }

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = 0;
        for (const auto& edge : edges) {
            n = max({n, edge[0], edge[1]});
        }

        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int depth = dfs(1, -1, adj);

        int ans = power(2, depth - 2);

        return ans % MOD;
    }
};
