// Problem Link : https://leetcode.com/problems/generate-parentheses/description/?envType=daily-question&envId=2026-10-02
class Solution {
public:
    vector<string> ans;
    void solve(string s, int n, int b) {
        if (b < 0)
            return;
        if (s.length() > 2 * n) return;

        if(b > n) return ;
        
        if (s.length() == 2 * n && b == 0) {
            ans.push_back(s);
            return;
        }

        solve(s + '(', n, b + 1);
        solve(s + ')', n, b - 1);
    }
    vector<string> generateParenthesis(int n) {
        solve("(", n, 1);
        return ans;
    }
};
