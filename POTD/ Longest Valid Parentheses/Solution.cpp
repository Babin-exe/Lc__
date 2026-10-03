// Problem Link : https://leetcode.com/problems/longest-valid-parentheses/description
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int ans = 0;
        int maxi = 0;

        int open = 0, close = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            } else {
                close++;
                if (open == close) {
                    ans = open + close;
                    maxi = max(maxi, ans);
                }

                if (close > open) {
                    open = 0, close = 0;
                }
            }
        }

        open = 0, close = 0, ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')') {
                close++;
            } else {
                open++;
                if (open == close) {
                    ans = open + close;
                    maxi = max(maxi, ans);
                }
                if (open > close) {
                    open = 0, close = 0;
                }
            }
        }

        return maxi;
    }
};
