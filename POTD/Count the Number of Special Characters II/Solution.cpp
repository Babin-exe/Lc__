// Problem Link : https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/?envType=daily-question&envId=2026-05-27

class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char, int> mp;
        int n = word.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            char ch = word[i];
            if (isupper(ch)) {
                if (mp.find(ch) == mp.end()) {
                    mp[ch] = i;
                }
            } else {
                mp[ch] = i;
            }
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (mp.find(ch) != mp.end() && mp.find(toupper(ch)) != mp.end()) {

                if (mp[ch] < mp[toupper(ch)])
                    ans++;
            }
        }
        return ans;
    }
};
