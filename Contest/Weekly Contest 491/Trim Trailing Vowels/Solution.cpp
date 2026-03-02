// Problem Link : https://leetcode.com/problems/trim-trailing-vowels/description/

class Solution {
public:
    bool isVowel(char ch) { return string("aeiou").find(ch) != string::npos; }
    string trimTrailingVowels(string s) {
        int last = s.length() - 1;
        while (last >= 0) {
            if (isVowel(s[last]))
                last--;
            else
                break;
        }
        if (last < 0)
            return "";
        return s.erase(last + 1, s.length() - 1);
    }
};
