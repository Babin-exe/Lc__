// Problem Link: https://leetcode.com/problems/string-compression-iii/
class Solution {
    public String compressedString(String word) {
        int n = word.length();
        StringBuilder ans = new StringBuilder("");
        for (int i = 0; i < n;) {
            int count = 0;
            char ch = word.charAt(i);
            while (i < n && count < 9 && ch == word.charAt(i)) {
                count++;
                i++;
            }
            ans.append(count).append(ch);
        }
        return ans.toString();
    }
}
