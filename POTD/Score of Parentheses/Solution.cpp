// Problem Link : https://leetcode.com/problems/score-of-parentheses/description/?envType=daily-question&envId=2026-10-05
class Solution {
public:
    int scoreOfParentheses(string s) {
        int b = 0;
        int t = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')') {
                b--;
                if (s[i - 1] == '(') {
                    t += (1 << b);
                }
            } else {
                b++;
            }
        }

        return t;
    }
};
