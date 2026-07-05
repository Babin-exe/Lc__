// Problem Link : https://leetcode.com/problems/subsequence-after-one-replacement/
class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        bool p = false;

        if (n > m)
            return false;

        int i = 0, j = 0;

        bool chance = true;
        while (i < n && j < m) {

            if (s[i] == t[j]) {
                i++;
                j++;
            } else if (s[i] != t[j] && chance) {
                i++;
                j++;
                chance = false;
            } else if (s[i] != t[j] && !chance) {
                while (j < m && s[i] != t[j]) {
                    j++;
                }
            }
        }
        if (i == n) {
            return true;
        }

        i = n - 1, j = m - 1;

        chance = true;
        while (i >= 0 && j >= 0) {

            if (s[i] == t[j]) {
                i--;
                j--;
            } else if (s[i] != t[j] && chance) {
                i--;
                j--;
                chance = false;
            } else {
                while (j >= 0 && s[i] != t[j]) {
                    j--;
                }
            }
        }

        return i <= -1;
    }
};
