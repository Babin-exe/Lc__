// Problem Link : https://leetcode.com/problems/count-the-number-of-complete-components/description/
class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        vector<int> size;
        map<int, int> mp;
        DSU(int n) {
            for (int i = 0; i < n; i++) {
                parent.push_back(i);
                size.push_back(1);
            }

            cout << "Parent set to itself and size to 1";
        }

        void Union(int a, int b) {
            int pa = findParent(a);
            int pb = findParent(b);

            if (pa == pb) {
                mp[pa]++;
                return;
            }
            if (size[pa] >= size[pb]) {
                parent[pb] = pa;
                size[pa] += size[pb];
                mp[pa] += mp[pb] + 1;
            } else {
                parent[pa] = pb;
                size[pb] += size[pa];
                mp[pb] += mp[pa] + 1;
            }
        }

        int findParent(int a) {
            if (parent[a] == a)
                return a;

            return parent[a] = findParent(parent[a]);
        }

        int getVertexSize(int p) { return size[p]; }
    };

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU d(n);
        for (int i = 0; i < edges.size(); i++) {
            d.Union(edges[i][0], edges[i][1]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int p = d.findParent(i);
            if (p == i) {
                int v = d.getVertexSize(i);
                int e = d.mp[i];
                if ((v * (v - 1) / 2) == e) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
