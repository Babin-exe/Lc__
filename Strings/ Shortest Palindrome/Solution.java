// Problem Link : https://leetcode.com/problems/shortest-palindrome/

class Solution {

    public void makeLps(String str, int[] LPS) {
        LPS[0] = 0;
        int length = 0;
        int n = str.length();
        int i = 1;
        while (i < n) {

            if (str.charAt(i) == (str.charAt(length))) {
                length++;
                LPS[i] = length;
                i++;
            } else {
                if (length == 0) {
                    LPS[i] = 0;
                    i++;
                } else {
                    length = LPS[length - 1];
                }
            }
        }

    }

    public String shortestPalindrome(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        String str = s + "^" + rev;
        int[] LPS = new int[str.length()];
        makeLps(str, LPS);
        int index = rev.length() - LPS[str.length() - 1];

        return rev.substring(0, index) + s;
    }
}
