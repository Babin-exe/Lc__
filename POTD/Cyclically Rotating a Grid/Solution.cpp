// Problem Link : https://leetcode.com/problems/cyclically-rotating-a-grid/description/?envType=daily-question&envId=2026-05-09

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int i = 0; i < layers; i++) {

            vector<int> temp;
            // Left column down push
            for (int lc = i; lc <= m - 1 - i; lc++) {
                temp.push_back(grid[lc][i]);
            }

            // Bottom row right
            for (int rb = i + 1; rb <= n - 1 - i; rb++) {
                temp.push_back(grid[m - 1 - i][rb]);
            }

            // right column  up
            for (int rc = m - 2 - i; rc >= i; rc--) {
                temp.push_back(grid[rc][n - 1 - i]);
            }

            // Top row right to left
            for (int tl = n - 2 - i; tl >= i + 1; tl--) {
                temp.push_back(grid[i][tl]);
            }

            int rot = k % temp.size();

            rotate(temp.rbegin(), temp.rbegin() + rot, temp.rend());

            int id = 0;
            for (int lc = i; lc <= m - 1 - i; lc++) {
                grid[lc][i] = temp[id++];
            }

            for (int rb = i + 1; rb <= n - 1 - i; rb++) {
                grid[m - 1 - i][rb] = temp[id++];
            }
            for (int rc = m - 2 - i; rc >= i; rc--) {
                grid[rc][n - 1 - i] = temp[id++];
            }
            for (int tl = n - 2 - i; tl >= i + 1; tl--) {
                grid[i][tl] = temp[id++];
            }
        }
        return grid;
    }
};
