// Problem Link : https://leetcode.com/problems/valid-parenthesis-string/description/?envType=daily-question&envId=2026-10-04
class Solution {
public:
    int n;
    int dp[101][101];
    bool solve(string& s, int i, int o) {
        if (i == n)
            return o == 0;

        bool v = false;
        if (dp[i][o] != -1)
            return dp[i][o];

        if (s[i] == '*') {
            v |= solve(s, i + 1, o + 1);
            v |= solve(s, i + 1, o);
            if (o > 0)
                v |= solve(s, i + 1, o - 1);
        } else if (s[i] == '(') {
            v |= solve(s, i + 1, o + 1);
        } else {
            if (o > 0) {
                v |= solve(s, i + 1, o - 1);
            }
        }
        return dp[i][o] = v;
    }
    bool checkValidString(string s) {
        n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 0);
    }
};
