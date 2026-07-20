// Problem Link : https://leetcode.com/problems/shift-2d-grid/description/
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        int t = (m * n);
        k %= t;

        auto reverse = [&](int l, int r) {
            while (l < r) {
                swap(grid[l / n][l % n], grid[r / n][r % n]);
                l++;
                r--;
            }
        };

        reverse(0, t - 1);
        reverse(0, k - 1);
        reverse(k, t - 1);

        return grid;
    }
};
