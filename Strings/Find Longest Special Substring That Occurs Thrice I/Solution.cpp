// Problem Link : https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/

class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> mp;
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            string st = "";
            for (int j = i; j < n; j++) {
                if (st.empty() || st.back() == s[j]) {
                    st.push_back(s[j]);
                    mp[st]++;
                } else {
                    break;
                }
            }
        }
        for (auto& it : mp) {
            if (it.first.length() > ans && it.second >= 3) {
                ans = it.first.length();
            }
        }
        return ans == 0 ? -1 : ans;
    }
};
