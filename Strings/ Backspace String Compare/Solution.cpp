// Problem link : https://leetcode.com/problems/backspace-string-compare/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m = s.length();
        int n = t.length();
        int i = m - 1;
        int j = n - 1;

        int skip_S = 0, skip_T = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    skip_S++;
                    i--;
                } else if (skip_S > 0) {
                    skip_S--;
                    i--;
                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (t[j] == '#') {
                    skip_T++;
                    j--;
                } else if (skip_T > 0) {
                    skip_T--;
                    j--;
                } else {
                    break;
                }
            }
            char auh = i < 0 ? '$' : s[i];
            char nsk = j < 0 ? '$' : t[j];
            if (auh != nsk)
                return false;
            i--;
            j--;
        }
        return true;
    }
};
