// Problem Link : https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/description
class Solution {
public:
    bool checkString(string s) {
        int a = -1, b = -1;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') {
                a = i;
            } else if (s[i] == 'b' && b == -1) {
                b = i;
            }
        }
        if (a < b || a == -1 || b == -1)
            return true;

        return false;
    }
};
