// Problem link : https://leetcode.com/problems/count-beautiful-substrings-ii/description/

class Solution {
public:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }

public:
#define ll long long
    long long beautifulSubstrings(string s, int k) {
        ll result = 0;
        ll vowel = 0;
        ll consonant = 0;
        unordered_map<ll, unordered_map<ll, ll>> mp;
        mp[0][0]++;

        for (char& ch : s) {

            if (isVowel(ch))
                vowel++;
            else
                consonant++;

            ll ps = vowel - consonant;

            for (auto& [pastVowel, count] : mp[ps]) {
                if ((vowel % k - pastVowel) * (vowel % k - pastVowel) % k == 0)
                    result += count;
            }
            mp[ps][vowel % k]++;
        }
        return result;
    }
};
