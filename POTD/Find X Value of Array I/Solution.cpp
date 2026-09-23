// Problem Link : https://leetcode.com/problems/find-x-value-of-array-i/description/?envType=daily-question&envId=2026-09-23
using ll = long long;
class Solution {
public:
    int dp[100001][5];
    vector<ll> ans;

    int n;

    vector<ll> solve(vector<int>& nums, int k) {
        for (int i = 1; i < n; ++i) {
            int v = nums[i] % k;

            for (int rem = 0; rem < k; ++rem) {
                dp[i][(rem * v) % k] += dp[i - 1][rem];
            }
            dp[i][v]++;

            for (int rem = 0; rem < k; ++rem) {
                ans[rem] += dp[i][rem];
            }
        }

        return ans;
    }

    vector<long long> resultArray(vector<int>& nums, int k) {
        memset(dp, 0, sizeof(dp));
        n = nums.size();
        ans = vector<ll>(k, 0);

        dp[0][nums[0] % k]++;
        ans[nums[0] % k]++;
        return solve(nums, k);
    }
};
