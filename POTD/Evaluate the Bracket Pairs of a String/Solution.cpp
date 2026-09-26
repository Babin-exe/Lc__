// Problem Link : https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/description/\
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto it : knowledge) {
            mp[it[0]] = it[1];
        }

        string ans;
        string key;

        int i = 0;
        bool open = false;
        int n = s.length();

        while (i < n) {

            if (!open && s[i] == '(') {
                open = true;
            } else if (open && s[i] != ')') {
                key += s[i];
            } else if (open && s[i] == ')') {
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } else {
                    ans += '?';
                }
                open = false;
                key = "";
            } else if (!open && s[i] != '(') {
                ans += s[i];
            }

            i++;
        }

        return ans;
    }
};
