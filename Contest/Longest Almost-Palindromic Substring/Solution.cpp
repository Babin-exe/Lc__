// Problem Link : https://leetcode.com/problems/longest-almost-palindromic-substring/description/

class Solution {
public:
    int solve(int left, int right, int n, string& s) {

        int length = 0;
        // See if the entire string is palindrome
        while (left >= 0 && right < n) {
            if (s[left] == s[right]) {
                left--;
                right++;
            } else
                break;
        }
        if (right - left - 1 == n)
            return n;

        // Try to skip one character from the left

        int lefty = left - 1;
        int righty = right;

        while (lefty >= 0 && righty < n) {
            if (s[lefty] == s[righty]) {
                lefty--;
                righty++;
            }
            else break;
        }

        length = max(length, righty - lefty - 1);

        int l = left;
        int r = right + 1;

        while (l >= 0 && r < n) {
            if (s[l] == s[r]) {
                l--;
                r++;
            } else
                break;
        }
        length = max(length, r - l - 1);

        return length;
    }
    int almostPalindromic(string s) {
        int n = s.length();
        int odd = 0, even = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            odd = solve(i, i, n, s);
            even = solve(i, i + 1, n, s);
            ans = max({ans, odd, even});
        }
        return ans;
    }
};
