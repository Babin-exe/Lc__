// Problem link : https://leetcode.com/problems/custom-sort-string/description/

class Solution {
public:
    string customSortString(string order, string s) {

        vector<int> vals(26, 0);
        string ans = "";
        int n = s.length();
        for (int i = 0; i < n; i++) {
            vals[s[i] - 'a']++;
        }

        int m = order.length();

        for (int i = 0; i < m; i++) {
            while (vals[order[i] - 'a'] > 0) {
                ans += order[i];
                vals[order[i] - 'a']--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (vals[s[i] - 'a'] > 0)
                ans += s[i];
        }
        return ans;
    }
};
