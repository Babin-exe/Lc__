// Problem Link : https://leetcode.com/problems/find-the-punishment-number-of-an-integer/

class Solution {
    public boolean solve(int i, int sum, String s, int n) {
        if (i == s.length())
            return n == sum;
        if (sum > n)
            return false;
        for (int j = i; j < s.length(); j++) {
            boolean hehe = false;
            int add = Integer.parseInt(s.substring(i, j + 1));
            hehe = solve(j + 1, sum + add, s, n);
            if (hehe) {
                return true;
            }
        }

        return false;
    }

    public int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            if (solve(0, 0, String.valueOf(sq), i)) {
                ans += sq;
            }
        }
        return ans;
    }
}
