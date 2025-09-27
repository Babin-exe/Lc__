// Problem link : https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/

class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0;
        int n = t.length();
        int s_mp[26] = {0};
        int t_mp[26] = {0};
        for (int i = 0; i < n; i++) {
            s_mp[s[i] - 'a']++;
            t_mp[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (s_mp[i] > t_mp[i])
                ans += (s_mp[i] - t_mp[i]);
        }
        return ans;
    }
};
