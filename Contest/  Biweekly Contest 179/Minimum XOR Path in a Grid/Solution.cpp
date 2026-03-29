// Problem Link : https://leetcode.com/problems/minimum-xor-path-in-a-grid/description/

// This got me tle : 

// class Solution {
// public:
//     int minCost(vector<vector<int>>& grid) {

//         int m = grid.size(), n = grid[0].size();
//         vector<vector<set<int>>> dp(m, vector<set<int>>(n));
//         dp[0][0].insert(grid[0][0]);

//         for (int j = 1; j < n; j++) {
//             for (auto& it : dp[0][j - 1]) dp[0][j].insert(it ^ grid[0][j]);
//         }

//         for (int i = 1; i < m; i++) {
//             for (auto& it : dp[i - 1][0]) dp[i][0].insert(it ^ grid[i][0]);
//         }

//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 for (auto& it : dp[i - 1][j]) dp[i][j].insert(it ^ grid[i][j]);
//                 for (auto& it : dp[i][j - 1]) dp[i][j].insert(it ^ grid[i][j]);
//             }
//         }
//         return *dp[m - 1][n - 1].begin();
//     }
// };


class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();

        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));

        dp[0][0].set(grid[0][0]);


        for (int j = 1; j < n; j++)
            for (int v = 0; v < 1024; v++)
                if (dp[0][j - 1].test(v))
                    dp[0][j].set(v ^ grid[0][j]);


        for (int i = 1; i < m; i++)
            for (int v = 0; v < 1024; v++)
                if (dp[i - 1][0].test(v))
                    dp[i][0].set(v ^ grid[i][0]);


        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                for (int v = 0; v < 1024; v++) {
                    if (dp[i - 1][j].test(v)) 
                        dp[i][j].set(v ^ grid[i][j]);
                    if (dp[i][j - 1].test(v)) 
                        dp[i][j].set(v ^ grid[i][j]);
                }

        for (int v = 0; v < 1024; v++)
            if (dp[m - 1][n - 1].test(v))
                return v;

        return -1;
    }
};
