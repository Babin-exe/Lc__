// Problem Link : https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/

class Solution {
    public int minChanges(String s) {
        int n = s.length();
        int i = 0;
        int count = 0;
        while (i < n - 1) {
            if (s.charAt(i) != s.charAt(i + 1))
                count++;

            i += 2;
        }
        return count;
    }
}
