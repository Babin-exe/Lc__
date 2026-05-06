// Problem Link : https://leetcode.com/problems/rotating-the-box/description/?envType=daily-question&envId=2026-05-06

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // for (int i = 0; i < m; ++i) {
        //     for (int j = n - 1; j >= 0; --j) {
        //         if (boxGrid[i][j] == '*' || boxGrid[i][j] == '.') {
        //             continue;
        //         }
        //         int init = j;
        //         for (int k = j + 1; k < n; k++) {
        //             if (boxGrid[i][k] == '.') {
        //                 init++;
        //             } else
        //                 break;
        //         }
        //         if (j != init)
        //             swap(boxGrid[i][j], boxGrid[i][init]);
        //     }
        // }

        for (int i = 0; i < m; i++) {
            int empty = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') {
                    empty = j-1;
                } else if (boxGrid[i][j] == '#') {
                    swap(boxGrid[i][j], boxGrid[i][empty]);
                    empty--;
                }
            }
        }

        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][i] = boxGrid[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(begin(ans[i]), end(ans[i]));
        }
        return ans;
    }
};
