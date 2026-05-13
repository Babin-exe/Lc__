// Problem Link : https://leetcode.com/problems/count-valid-word-occurrences/description/
class Solution {
public:
    bool Char(char ch) { return (ch >= 'a' && ch <= 'z'); }
    vector<int> countWordOccurrences(vector<string>& chunks,
                                     vector<string>& queries) {

        map<string, int> mp;
        vector<int> ans;
        string s = "";
        for (auto& it : chunks)
            s += it;
        int n = s.length();
        string t = "";
        for (int i = 0; i < n; i++) {
            if (Char(s[i])) {
                t.push_back(s[i]);
            } else if (s[i] == '-' && i != 0 && i != n - 1 && Char(s[i - 1]) &&
                       Char(s[i + 1])) {
                t.push_back(s[i]);
            } else {
                if (!t.empty()) {
                    mp[t]++;
                    t = "";
                }
            }
        }
        mp[t]++;
        int k = queries.size();
        for (int i = 0; i < k; i++) {
            ans.push_back(mp[queries[i]]);
        }
        return ans;
    }
};
