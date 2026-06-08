// Problem Link : https://leetcode.com/problems/maximum-total-value-of-covered-indices/description/
class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        long long ans = 0;
        int l = 0;
        int n = s.length();
        while (l < n) {

            if (s[l] == '0') {
                int t = l + 1;
                int m = INT_MAX;
                while (t < n && s[t] == '1') {
                    m = min(m, nums[t]);
                    ans += nums[t];
                    t++;
                }

                if (nums[l] > m) {
                    ans -= m;
                    ans += nums[l];
                }
            }
            l++;
        }

        if (l == n) {
            for (int i = 0; i < n; i++) {
                if (s[i] == '1')
                    ans += nums[i];
                else
                    break;
            }
        }

        return ans;
    }
};
