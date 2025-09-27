// Problem link : https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
class Solution {
    public int minSteps(String s, String t) {
        int[] a = new int[26];
        int count = 0;
        int[] b = new int[26];
        for (int i = 0; i < s.length(); i++) {
            char achar = s.charAt(i);
            char bchar = t.charAt(i);
            a[achar - 'a']++;
            b[bchar - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (a[i] > b[i]) {
                count += (a[i] - b[i]);
            }
        }
        return count;
    }
}
