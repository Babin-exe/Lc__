// Problem Link : https://leetcode.com/problems/remove-outermost-parentheses/
class Solution {
public:
    string removeOuterParentheses(string s) {

        string t;
        int c = 0;

        for (auto ch : s) {

            if (ch == '(') {
                if (c > 0) t += ch;
                c++;
            } else {
                c--;
                if (c > 0) t += ch;
            }
        }

        return t;
    }
};
