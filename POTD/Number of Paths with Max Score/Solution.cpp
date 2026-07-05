// Problem Link : https://leetcode.com/problems/number-of-paths-with-max-score/description/?envType=daily-question&envId=2026-07-05
using ll = long long;
const int MOD = 1e9 + 7;
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();

        vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(n, {0, 0}));

        dp[n - 1][n - 1] = {0, 1};

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X') {
                    dp[i][j] = {-1, 0};
                    continue;
                }

                if (i == n - 1 && j == n - 1)
                    continue;

                ll cost = -1;
                ll paths = 0;

                auto explore = [&](int ni, int nj) {
                    if (ni == n || nj == n)
                        return;

                    if (dp[ni][nj].first == -1 && dp[ni][nj].second == 0)
                        return;

                    ll pcost = dp[ni][nj].first;
                    ll ppaths = dp[ni][nj].second;

                    if (pcost > cost) {
                        cost = pcost;
                        paths = ppaths;
                    } else if (pcost == cost) {
                        paths = (paths + ppaths) % MOD;
                    }
                };

                explore(i + 1, j);
                explore(i, j + 1);
                explore(i + 1, j + 1);

                if (cost == -1) {
                    dp[i][j] = {-1, 0};
                    continue;
                }

                ll myval = isdigit(board[i][j]) ? board[i][j] - '0' : 0;
                dp[i][j].first = (myval % MOD + cost % MOD) % MOD;
                dp[i][j].second = paths % MOD;
            }
        }
        if (dp[0][0].first == -1)
            return {0, 0};

        return {(int)dp[0][0].first, (int)dp[0][0].second};
    }
};
