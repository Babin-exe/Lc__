// Problem Link : https://leetcode.com/problems/permutation-in-string/

class Solution {

    public boolean matches(int[] freq1, int[] freq2) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i])
                return false;
        }
        return true;
    }

    public boolean checkInclusion(String s1, String s2) {

        if (s1.length() > s2.length())
            return false;

        int[] freq1 = new int[26];
        int[] freq2 = new int[26];

        for (char ch : s1.toCharArray()) {
            freq1[ch - 'a']++;
        }

        int k = s1.length();
        int n = s2.length();

        for (int i = 0; i < n; i++) {

            freq2[s2.charAt(i) - 'a']++;

            if (i >= k) {
                freq2[s2.charAt(i - k) - 'a']--;
            }

            if (i >= k - 1 && matches(freq1, freq2))
                return true;
        }

        return false;
    }
}
