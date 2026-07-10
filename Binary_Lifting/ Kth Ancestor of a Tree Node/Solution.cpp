// Problem Link :https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/
class TreeAncestor {
public:
    int row;
    int col;
    vector<vector<int>> up;

    TreeAncestor(int n, vector<int>& parent) {
        row = n;
        col = log2(n) + 1;

        up.resize(row, vector<int>(col, -1));

        //[node][0] 2^0 = 1 so , just one step up is the parent itself
        for (int i = 0; i < n; i++) {
            up[i][0] = parent[i];
        }

        for (int power = 1; power < col; power++) {
            for (int r = 0; r < row; r++) {
                if (up[r][power - 1] != -1) {
                    cout << up[r][power - 1] << "\n";
                    up[r][power] = up[up[r][power - 1]][power - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {

        for (int i = 0; i < col; i++) {
            if (k & (1 << i)) {
                node = up[node][i];
            }
            if (node == -1)
                return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
