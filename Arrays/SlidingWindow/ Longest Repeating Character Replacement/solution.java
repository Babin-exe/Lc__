// Problem link : https://leetcode.com/problems/longest-repeating-character-replacement/?source=submission-ac


class Solution {
    public int characterReplacement(String s, int k) {

        int i = 0, n = s.length();
        int maxi = Integer.MIN_VALUE;
        int freq = 0;
        int[] hehe = new int[26];
        for (int j = 0; j < n; j++) {

            hehe[s.charAt(j) - 'A']++;
            freq = Math.max(freq, hehe[s.charAt(j) - 'A']);

            while ((j - i + 1) - freq > k) {
                hehe[s.charAt(i) - 'A']--;
                i++;
            }
            maxi = Math.max(maxi, j - i + 1);

        }
        return maxi;

    }
}
