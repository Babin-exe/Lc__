// Problem Link : https://leetcode.com/problems/generate-parentheses/?

class Solution {

    List<String> ans = new ArrayList<>();

    public void solve(int o, int c, StringBuilder sb) {

        if (o == 0 && c == 0) {
            ans.add(sb.toString());
            return;
        }

        if (o > c)
            return;

        if (o > 0) {

            solve(o - 1, c, sb.append("("));
            sb.deleteChatAt(sb.length() - 1);
        }
        if (c > 0) {

            solve(o, c - 1, sb.append(")"));
            sb.deleteChatAt(sb.length() - 1);
        }

    }

    public List<String> generateParenthesis(int n) {
        solve(n, n, new StringBuilder());
        return ans;
    }
}
