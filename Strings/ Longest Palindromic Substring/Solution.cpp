// Problem link : https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 0;
        int a;
        // For odd length center
        for (int i = 0; i < n; i++) {
            int k = 0;
            while (i - k >= 0 && i + k < n && s[i + k] == s[i - k]) {
                k++;
            }
            k--;
            if ((i + k) - (i - k) + 1 > maxlen) {
                a = i - k;
                maxlen = (i + k) - (i - k) + 1;
            }
        }

        // For even length
        for (double i = 0.5; i < n; i++) {
            double k = 0.5;
            while (i - k >= 0 && i + k < n && s[i + k] == s[i - k]) {
                k++;
            }
            k--;
            if ((i + k) - (i - k) + 1 > maxlen) {
                a = i - k;
                maxlen = (i + k) - (i - k) + 1;
            }
        }
        return s.substr(a, maxlen);
    }
};
