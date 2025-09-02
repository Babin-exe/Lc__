// Problem link : https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {

        int left_word = 0;
        int i = 0;
        int right_word = 0;
        int j = 0;
        int m = word1.length;
        int n = word2.length;

        while (left_word < m && right_word < n) {

            if (word1[left_word].charAt(i) != word2[right_word].charAt(j))
                return false;

            i++;
            j++;
            if (i == word1[left_word].length()) {
                i = 0;
                left_word++;
            }
            if (j == word2[right_word].length()) {
                j = 0;
                right_word++;
            }

        }
        return left_word == m && right_word == n;

    }
}
