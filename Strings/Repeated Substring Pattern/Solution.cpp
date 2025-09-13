// Problem link : https://leetcode.com/problems/repeated-substring-pattern/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int i = 1; i <= n / 2; i++) {
            if (n % i != 0)
                continue;
            string sub = s.substr(0, i);
            string ans;
            ans.reserve(n);
            for (int j = 1; j <= n / i; j++) {
                ans.append(sub);
            }
            if (ans == s)
                return true;
        }
        return false;
    }
};
