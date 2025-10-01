// Problem link : https://leetcode.com/problems/custom-sort-string/description/
class Solution {
    public String customSortString(String order, String s) {

        int[] values = new int[26];
        int m = order.length();
        int n = s.length();
        StringBuilder hehe = new StringBuilder("");

        for (int i = 0; i < n; i++) {
            values[s.charAt(i) - 'a']++;
        }

        for (int i = 0; i < m; i++) {
            char ch = order.charAt(i);
            while (values[ch - 'a'] > 0) {
                hehe.append(ch);
                values[ch - 'a']--;
            }
        }

        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (values[ch - 'a'] > 0) {
                hehe.append(ch);
            }
        }
        return hehe.toString();
    }
}
