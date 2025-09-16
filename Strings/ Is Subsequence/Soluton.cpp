// Problem link : https://leetcode.com/problems/is-subsequence/description/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (m == index)
                break;

            if (t[i] == s[index]) {
                index++;
            }
        }
        return index == m;
    }
};
