// Problem Link : https://leetcode.com/problems/count-subarrays-with-loose-bounds/
using ll = long long;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        vector<ll> dp(n + 1, 0);
        ll ans = 0;
        if (nums[0] >= minK && nums[0] <= maxK) {
            dp[0] = 1;
        }
        ans += dp[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] >= minK && nums[i] <= maxK) {
                dp[i] = dp[i - 1] + 1;
                ans += dp[i];
            }
        }
        return ans;
    }
};
