// Problem Link : https://leetcode.com/problems/largest-local-values-in-a-matrix-ii/description/
#include <bits/stdc++.h>
using namespace std;

const int LOG = 8;
const int MAX_N = 201;

// one sparse table per row
int m[MAX_N][MAX_N][LOG];
int n, col;

void build(int row, vector<int>& a) {
    for (int i = 0; i < col; i++)
        m[row][i][0] = a[i];

    for (int k = 1; k < LOG; k++)
        for (int i = 0; i + (1 << k) - 1 < col; i++)
            m[row][i][k] =
                max(m[row][i][k - 1], m[row][i + (1 << (k - 1))][k - 1]);
}

int queryMax(int row, int l, int r) {
    if (l > r)
        return 0;
    l = max(l, 0);
    r = min(r, col - 1);
    int len = r - l + 1;
    int k = 31 - __builtin_clz(len);
    return max(m[row][l][k], m[row][r - (1 << k) + 1][k]);
}

class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        n = matrix.size();
        col = matrix[0].size();

        // build sparse table for each row
        for (int i = 0; i < n; i++)
            build(i, matrix[i]);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < col; j++) {
                int v = matrix[i][j];
                if (!v)
                    continue;

                bool isMax = true;

                for (int ki = max(0, i - v); ki <= min(n - 1, i + v); ki++) {
                    int val;
                    // top and bottom rows → narrower column range
                    if (ki == i - v || ki == i + v)
                        val = queryMax(ki, j - v + 1, j + v - 1);
                    // middle rows → full column range
                    else
                        val = queryMax(ki, j - v, j + v);

                    if (val > v) {
                        isMax = false;
                        break;
                    }
                }

                if (isMax)
                    cnt++;
            }
        }
        return cnt;
    }
};
