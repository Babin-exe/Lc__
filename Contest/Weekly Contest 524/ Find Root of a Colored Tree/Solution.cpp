// Problem Link :https://leetcode.com/problems/find-root-of-a-colored-tree/

class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = edges.size();

        int root_default = -1;
        vector<int> in(n + 1, 0);
        vector<int> out(n + 1, 0);

        auto giveParent = [](char ch) -> char {
            if (ch == 'R')
                return 'W';
            else if (ch == 'W')
                return 'B';
            else
                return 'R';
        };

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];

            // If u is parent and the tree is like u->v
            if (colors[u] == giveParent(colors[v])) {
                out[u]++;
                in[v]++;

            } // If v is the parent and the tree is like  v->u
            else if (colors[v] == giveParent(colors[u])) {
                out[v]++;
                in[u]++;
            }
            /*
            Both parent and child are of same color
            and this violates the condition of cycle
            so this is for sure invalid itself
            */

            else
                return -1;
        }

        for (int i = 0; i < n+1; i++) {
            // This thing is the root because of in degree begin 0
            if (in[i] == 0) {
                // Somehow we are visiting twice for the root
                if (root_default != -1)
                    return -1;
                root_default = i;
            }

            // one node can come from one parent only  , like if u is the parent
            // and v is the child u ->  v is good but this is not good u ,v -> x
            // so in value can be at max 1 and at min 0 ...
            else if (in[i] != 1) return -1;

                // A node can have at max 2 children , anything more makes the
                // tree not be a binary tree
                if (out[i] > 2)
                    return -1;
        }
        return root_default;
    }
};
