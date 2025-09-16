// Problem link : https://leetcode.com/problems/remove-duplicate-letters/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        vector<bool> pr(26, false);
        vector<int> index(26);
        for (int i = 0; i < s.length(); i++) {
            index[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (pr[ch - 'a'] == true)
                continue;

            while (ans.length() > 0 && ch < ans.back() &&
                   index[ans.back() - 'a'] > i) {
                pr[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(ch);
            pr[ch - 'a'] = true;
        }

        return ans;
    }
};
