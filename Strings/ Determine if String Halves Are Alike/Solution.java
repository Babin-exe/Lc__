// Problem link : https://leetcode.com/problems/determine-if-string-halves-are-alike/description/

class Solution {
    public boolean isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

    

    public boolean halvesAreAlike(String s) {
        int n = s.length();
        int i = 0, j = n / 2;
        int left_count = 0, right_count = 0;
        while (i < n / 2 && j < n) {
            if (isVowel(s.charAt(i)))
                left_count++;
            if (isVowel(s.charAt(j)))
                right_count++;
            i++;
            j++;
        }

        return (left_count == right_count);
    }
}
