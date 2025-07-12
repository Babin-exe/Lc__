// Problem Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
class Solution {
    public int lengthOfLongestSubstring(String s) {

        int i = 0, j = 0, n = s.length();
        int count = 0;

        while (j < n) {

            boolean check = false;
            int take = i;

            while (take < j) {
                if (s.charAt(take) == s.charAt(j)) {
                    check = true;
                    i = take+1;
                    break;
                }
                take++;
            }
            if (!check) {
                count = Math.max(count,j - i + 1);
            }

            j++;
        }
        return count;
    }
}
