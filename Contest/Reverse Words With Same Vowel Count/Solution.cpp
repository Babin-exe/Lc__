// Problem Link : https://leetcode.com/problems/reverse-words-with-same-vowel-count/description/
class Solution {
public:
    void reverse(string& s, int l, int r) {
        if (l < 0 || r >= s.length() || l >= r)
            return;
        for (; l < r; l++, r--) {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
        }
    }
    bool isVowle(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
    string reverseWords(string s) {
        int count = 0;
        int i = 0;
        while (i < s.length() && s[i] != ' ') {
            if (isVowle(s[i])) {

                count++;
            }
            i++;
        }
        int n = s.length();
        int j = i + 1;
        while (j < n) {

            int r = j;
            int l = r;
            int c = 0;

            while (r < n && s[r] != ' ') {
                if (isVowle(s[r])) {
                    c++;
                }
                r++;
            }

            if (c == count) {
                reverse(s, l, r - 1);
            }
            j = r + 1;
        }
        return s;
    }
};
