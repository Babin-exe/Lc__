// Problem Link : https://leetcode.com/problems/sort-vowels-by-frequency/description/

class Solution {
public:
    string sortVowels(string s) {

        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                   ch == 'u';
        };
        int n = s.size();

        vector<char> stuff;
        unordered_map<char, int> count;
        unordered_map<char, int> pos;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (isVowel(ch)) {
                stuff.push_back(ch);
                count[ch]++;
                if (pos.find(ch) == pos.end()) {
                    pos[ch] = i;
                }
            }
        }

        sort(begin(stuff), end(stuff), [&](char a, char b) {
            if (count[a] != count[b])
                return count[a] > count[b];
            return pos[a] < pos[b];
        });
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                s[i] = stuff[k];
                k++;
            }
        }
        return s;
    }
};
