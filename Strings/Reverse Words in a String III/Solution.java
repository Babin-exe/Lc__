// problem link : https://leetcode.com/problems/reverse-words-in-a-string-iii/submissions/1773685259/
class Solution {

    private void reverse(char[] auh, int start, int end) {

        while (start < end) {
            char temp = auh[start];
            auh[start] = auh[end];
            auh[end] = temp;
            start++;
            end--;
        }

    }

    public String reverseWords(String s) {
        char[] auh = s.toCharArray();
        int n = auh.length;

        for (int i = 0; i < n; i++) {
            if (auh[i] != ' ') {
                int j = i;
                while (j < n && auh[j] != ' ') {
                    j++;
                }
                reverse(auh, i, j - 1);
                i = j;
            }

        }
        return new String(auh);
    }
}

