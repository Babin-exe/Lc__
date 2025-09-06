// Problem link : https://leetcode.com/problems/concatenated-words/

class Solution {
    unordered_map<string, bool> mp;

public:
    bool isConcatenated(string word, unordered_set<string>& st) {
        int l = word.length();
        if (mp.find(word) != mp.end()) {
            return mp[word];
        }

        for (int i = 0; i < l; i++) {
            string prefix = word.substr(0, i + 1);
            string postfix = word.substr(i + 1);
            if ((st.find(prefix) != st.end() && st.find(postfix) != st.end()) ||
                st.find(prefix) != st.end() && isConcatenated(postfix, st)) {
                return mp[word] = true;
            }
        }
        return mp[word] = false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        mp.clear();
        int n = words.size();
        unordered_set<string> st(begin(words), end(words));
        vector<string> result;
        for (int i = 0; i < n; i++) {
            string word = words[i];
            if (isConcatenated(word, st)) {
                result.push_back(words[i]);
            }
        }
        return result;
    }
};
