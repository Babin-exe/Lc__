// Problem Link : https://leetcode.com/problems/minimum-operations-to-transform-binary-string/description/
using ll = long long;
class Solution {
public:
    int minOperations(string s1, string s2) {

        if (s1 == s2)
            return 0;

        int n = s1.length();

        if (n == 1) {
            if (s1[0] == '0' && s2[0] == '1')
                return 1;
            else
                return -1;
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {

            if (s1[i] == s2[i])
                continue;
            else if (s1[i] == '0' && s2[i] == '1') {
                ans++;
                s1[i] = '1';
            } else if (s1[i] == '1' && s2[i] == '0') {
                if (i != n - 1) {
                    if (s1[i + 1] == '1') {
                        ans++;
                        s1[i + 1] = '0';
                    } else {
                        ans += 2;
                    }

                } else if (i == n - 1) {
                    if (s1[i - 1] == '0' || s1[i - 1] == '1') {
                        ans += 2;
                    } 
                }
            }
        }
        return ans;
    }
};
