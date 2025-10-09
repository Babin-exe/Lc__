// Problem Link : https://leetcode.com/problems/separate-black-and-white-balls/description/

class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        long long o_c = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                ans += o_c;
            else
                o_c++;
        }
        return ans;
    }
};
