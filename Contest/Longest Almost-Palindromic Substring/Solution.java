// Problem Link : https://leetcode.com/problems/longest-almost-palindromic-substring/

class Solution {

    private int solve(int left, int right, int n, String s) {
        int length = 0;

        // Check if the entire string is palindrome
        while (left >= 0 && right < n) {
            if (s.charAt(left) == s.charAt(right)) {
                left--;
                right++;
            } else {
                break;
            }
        }

        if (right - left - 1 == n)
            return n;

        // Try to skip one character from the left
        int lefty = left - 1;
        int righty = right;

        while (lefty >= 0 && righty < n) {
            if (s.charAt(lefty) == s.charAt(righty)) {
                lefty--;
                righty++;
            } else {
                break;
            }
        }

        length = Math.max(length, righty - lefty - 1);

        // Try to skip one character from the right
        int l = left;
        int r = right + 1;

        while (l >= 0 && r < n) {
            if (s.charAt(l) == s.charAt(r)) {
                l--;
                r++;
            } else {
                break;
            }
        }

        length = Math.max(length, r - l - 1);

        return length;
    }

    public int almostPalindromic(String s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int odd = solve(i, i, n, s);
            int even = solve(i, i + 1, n, s);
            ans = Math.max(ans, Math.max(odd, even));
        }

        return ans;
    }
}
