// Problem Link : https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/
class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        int m = str1.length();
        int n = str2.length();

        int i = 0, j = 0;
        while (i < m && j < n) {
            char c1 = str1.charAt(i);
            char c2 = str2.charAt(j);

            if (c1 == c2) {
                i++;
                j++;
            } else if ((c1 + 1 == c2) || (c1 == 'z' && c2 == 'a')) {
            
                i++;
                j++;
            } else {
                i++;
            }
        }

        return j == n;
    }
}
