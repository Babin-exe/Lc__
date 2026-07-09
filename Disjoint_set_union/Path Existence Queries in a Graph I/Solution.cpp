// Problem Link : https://leetcode.com/problems/path-existence-queries-in-a-graph-i/
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int v) {
        if (parent[v] == v)
            return v;

        return parent[v] = find(parent[v]);
    }

    void unionByRank(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb)
            return;

        if (rank[pa] == rank[pb]) {
            parent[pb] = pa;
            rank[pa]++;
        } else if (rank[pa] > rank[pb]) {
            parent[pb] = pa;
        } else {
            parent[pa] = pb;
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        DSU dsu(n);

        for (int i = 1; i < n; i++) {

            if (nums[i] - nums[i - 1] <= maxDiff) {
                dsu.unionByRank(i, i - 1);
            }
        }

        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(dsu.find(q[0]) == dsu.find(q[1]));
        }

        return ans;
    }
};
