// Problem link :https://leetcode.com/problems/sort-vowels-in-a-string/ 
class Solution {

public:
    bool isVowel(char c) {
        static unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                             'A', 'E', 'I', 'O', 'U'};
        return vowels.count(c);
    }

public:
    string sortVowels(string s) {
        vector<int> index;
        vector<char> vowel;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                index.push_back(i);
                vowel.push_back(s[i]);
            }
        }
        sort(begin(vowel), end(vowel));
        for (int i = 0; i < vowel.size(); i++) {
            s[index[i]] = vowel[i];
        }
        return s;
    }
};
