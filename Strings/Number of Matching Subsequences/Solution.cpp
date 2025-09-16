// Problem link: https://leetcode.com/problems/number-of-matching-subsequences/

class Solution {

public:
    bool isValid(string t, map<char, vector<int>> &mp) {
        int prev = -1;
        for (int i = 0; i < t.length(); i++) {
            if (mp.find(t[i]) == mp.end())
                return false;

            vector<int> &hehe = mp[t[i]];
            auto iterator = upper_bound(begin(hehe), end(hehe), prev);
            if (iterator == hehe.end())
                return false;

            prev = *iterator;
        }
        return true;
    }

public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        map<char, vector<int>> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]].push_back(i);
        }

        for (int i = 0; i < words.size(); i++) {
            if (isValid(words[i], mp))
                ans++;
        }

        return ans;
    }
};
