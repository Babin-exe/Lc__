// Problem Link : https://leetcode.com/problems/check-adjacent-digit-differences/description/
class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            char l = s[i] - '0';
            char r = s[i + 1] - '0';
            if (abs(l - r) > 2)
                return false;
        }
        return true;
    }
};
