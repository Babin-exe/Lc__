// Problem Link : https://leetcode.com/problems/minimum-flips-to-make-binary-string-coherent/
class Solution {
public:
    int minFlips(string s) {
        int zero_count = 0, one_count = 0;
        for (char ch : s) {
            if (ch == '1')
                one_count++;
            else
                zero_count++;
        }

        int ans = min(zero_count, one_count);
        ans = min(ans, one_count - 1);

        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if ((i == 0 || i == n - 1) && s[i] == '0') {
                cnt++;
            } else if ((i > 0 && i < n - 1) && s[i] == '1') {
                cnt++;
            }
        }
        ans = min(ans, cnt);
        ans = max(ans, 0);
        return ans;
    }
};
