// Problem link : https://leetcode.com/problems/repeated-substring-pattern/
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int n = s.length();

        for (int i = 1; i <= n / 2; i++) {
            if (n % i != 0)
                continue;

            String auh = s.substring(0, i);
            StringBuilder ans = new StringBuilder("");

            for (int j = 0; j < n / i; j++) {
                ans.append(auh);
            }
            if (ans.toString().equals(s))
                return true;

        }

        return false;
    }
}
