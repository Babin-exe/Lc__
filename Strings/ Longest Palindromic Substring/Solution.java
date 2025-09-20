// Problem link : https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
    Boolean[][] dp;

    public boolean isPalindrome(String s, int i, int j) {
        if (i >= j)
            return true;

        if (dp[i][j] != null)
            return dp[i][j];

        if (s.charAt(i) == s.charAt(j)) 
            dp[i][j] = isPalindrome(s, i + 1, j - 1);
            else
            dp[i][j] = false;

        return dp[i][j];
    }

    public String longestPalindrome(String s) {
        int n = s.length();
        dp = new Boolean[n][n];
        int len = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    if (j - i + 1 > len) {
                        len = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substring(start, start + len);
    }
}
