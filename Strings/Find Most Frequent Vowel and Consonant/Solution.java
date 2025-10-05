// https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/

class Solution {

    public boolean isVowel(char ch) {
        return "aeiou".indexOf(ch) != -1;
    }

    public int maxFreqSum(String s) {
        int max_vowel = 0;
        int max_consonant = 0;
        int[] val = new int[26];
        for (char ch : s.toCharArray()) {

            val[ch - 'a']++;
            if (isVowel(ch)) {
                max_vowel = Math.max(max_vowel, val[ch - 'a']);
            } else {
                max_consonant = Math.max(max_consonant, val[ch - 'a']);
            }

        }
        return max_vowel + max_consonant;

    }
}
