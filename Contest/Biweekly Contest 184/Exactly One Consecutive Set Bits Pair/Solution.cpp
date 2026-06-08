// Problem Link : https://leetcode.com/problems/exactly-one-consecutive-set-bits-pair/description/

class Solution {
public:
    bool consecutiveSetBits(int n) {
        string s;
        int t = n;
        while (t != 0) {
            s += char((t % 2) + '0');
            t /= 2;
        }

        int nn = s.length();
        int c = 0;
        for (int i = 0; i < nn - 1; i++) {
            if (s[i] == '1' && s[i + 1] == '1') {
                c++;
            }
            if (c >= 2)
                return false;
        }
        if (c == 1)
            return true;
        return false;
    }
};
