// Problem Link : https://leetcode.com/problems/cyclically-shift-rows-and-columns/description/
class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid,
                                    vector<int>& rowShift,
                                    vector<int>& colShift) {

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            int shift = rowShift[i] % n;

            for (int j = shift; j < n; j++) {
                temp.push_back(grid[i][j]);
            }

            for (int j = 0; j < shift; ++j) {
                temp.push_back(grid[i][j]);
            }

            grid[i] = temp;
        }

        for (int i = 0; i < n; i++) {

            vector<int> temp;
            int shift = colShift[i] % n;

            for (int j = shift; j < n; ++j) {
                temp.push_back(grid[j][i]);
            }

            for (int j = 0; j < shift; ++j) {
                temp.push_back(grid[j][i]);
            }

            for (int j = 0; j < n; ++j) {
                grid[j][i] = temp[j];
            }
        }

        return grid;
    }
};
