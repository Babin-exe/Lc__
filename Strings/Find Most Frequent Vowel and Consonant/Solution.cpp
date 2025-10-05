// Problem Link : https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/description/


class Solution {
public:
    bool isVowel(char ch) {
        return string("aeiou").find(ch) != string::npos;
    }

    int maxFreqSum(string s) {
        int max_vowel = 0;
        int max_consonant = 0;
        vector<int> val(26, 0);

        for (char ch : s) {
            val[ch - 'a']++;

            if (isVowel(ch))
                max_vowel = max(max_vowel, val[ch - 'a']);
            else
                max_consonant = max(max_consonant, val[ch - 'a']);
        }

        return max_vowel + max_consonant;
    }
};
