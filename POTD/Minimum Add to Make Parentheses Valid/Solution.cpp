// Problem Link : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
class Solution {
public:
    int minAddToMakeValid(string s) {

        int ans = 0;
        int c = 0;


        for (auto ch : s) {
            if (ch == '(') {
                ans++;
            } else {
                ans--;
                if (ans < 0) {
                    c++;
                    ans = 0;
                }
            }
        }

        return c + (ans > 0 ? ans : 0);
    }
};
