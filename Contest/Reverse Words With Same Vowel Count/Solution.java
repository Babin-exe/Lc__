// Problem Link : https://leetcode.com/problems/reverse-words-with-same-vowel-count/description/
class Solution {

    private boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    private void reverse(char[] s, int l, int r) {
        while (l < r) {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;
            r--;
        }
    }

    public String reverseWords(String s) {
        char[] arr = s.toCharArray();
        int n = arr.length;

        int i = 0, firstVowelCount = 0;
        while (i < n && arr[i] != ' ') {
            if (isVowel(arr[i]))
                firstVowelCount++;
            i++;
        }

        int j = i;
        while (j < n) {

            while (j < n && arr[j] == ' ')
                j++;
            if (j >= n)
                break;

            int l = j, r = j;
            int vowelCount = 0;

            while (r < n && arr[r] != ' ') {
                if (isVowel(arr[r]))
                    vowelCount++;
                r++;
            }

            if (vowelCount == firstVowelCount) {
                reverse(arr, l, r - 1);
            }

            j = r + 1;
        }

        return new String(arr);
    }

}
