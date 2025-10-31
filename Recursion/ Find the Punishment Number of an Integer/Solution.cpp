// Problem Link : https://leetcode.com/problems/find-the-punishment-number-of-an-integer/

class Solution {
public:
    bool solve(int i, int sum, string s, int n) {

        if (i == s.length())
            return n == sum;
        if (sum > n)
            return false;
        bool hehe = false;
        for (int j = i; j < s.length(); j++) {
            int val = stoi(s.substr(i, j - i + 1));
            hehe = solve(j + 1, sum + val, s, n);
            if (hehe == true) {
                return true;
            }
        }

        return false;
    }

public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            if (solve(0, 0, to_string(sq), i)) {
                ans += sq;
            }
        }

        return ans;
    }
};
