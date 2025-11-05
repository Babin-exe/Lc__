// Problem Link : https://leetcode.com/problems/generate-parentheses/?

class Solution {
public:
    vector<string> ans;

    void solve(int open, int close, string& s) {
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }
        if (open > close)
            return;

        if (open > 0) {
            s.push_back('(');
            solve(open - 1, close, s);
            s.pop_back();
        }
        if (close > 0) {
            s.push_back(')');
            solve(open, close - 1, s);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(n, n, s);
        return ans;
    }
};
