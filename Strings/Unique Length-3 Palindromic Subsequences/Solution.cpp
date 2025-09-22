// Problem link : https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/

class Solution {

public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            unordered_set<char> m;
            if (first[i] == -1 || last[i] - first[i] <= 1)
                continue;

            for (int a = first[i] + 1; a < last[i]; a++) {
                if (m.find(s[a]) == m.end()) {
                    ans++;
                    m.insert(s[a]);
                }
            }
        }
        return ans;
    }
};
