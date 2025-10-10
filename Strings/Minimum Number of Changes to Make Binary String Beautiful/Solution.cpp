// Problem Link : https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/

class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int i = 0;
        int ans = 0;
        while (i < n - 1) {
            if (s[i] != s[i + 1])
                ans++;

            i += 2;
        }
        return ans;
    }
};
