// Problem link : https://leetcode.com/problems/decoded-string-at-index/description/

class Solution {
    public String decodeAtIndex(String s, int k) {
        long size = 0;
        int n = s.length();
        for (char ch : s.toCharArray()) {

            if (Character.isDigit(ch)) {
                size *= (ch - '0');
            } else {
                size = size + 1;
            }
        }

        int idx = n - 1;
        while (idx >= 0) {
            k %= size;
            char ch = s.charAt(idx);
            if (k == 0 && Character.isLetter(ch))
                return "" + ch;

            if (Character.isDigit(ch)) {
                size /= ch - '0';
            } else {
                size--;
            }
            idx--;
        }
        return "";
    }
}
