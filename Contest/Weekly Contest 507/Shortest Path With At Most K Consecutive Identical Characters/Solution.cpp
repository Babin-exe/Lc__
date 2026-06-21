// Problem Link : https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/description/

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        int ans = INT_MAX;
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges)
            adj[e[0]].push_back({e[1], e[2]});

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, node, cons] = pq.top();
            pq.pop();

            if (cost > dist[node][cons])
                continue;

            for (auto [nnode, pcost] : adj[node]) {
                int new_cons = (labels[node] == labels[nnode]) ? cons + 1 : 1;
                if (new_cons > k)
                    continue;

                if (cost + pcost < dist[nnode][new_cons]) {
                    dist[nnode][new_cons] = cost + pcost;
                    pq.push({cost + pcost, nnode, new_cons});
                }
            }
        }

        for (int c = 1; c <= k; c++) {
            ans = min(ans, dist[n - 1][c]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
