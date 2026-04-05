// Problem Link : https://leetcode.com/problems/minimum-removals-to-achieve-target-xor/description/

class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int maxi = 1e5;
        vector<int> dp(maxi, -1);
        int n = nums.size();
        dp[0] = 0;

        for (auto& x : nums) {
            vector<int> ndp = dp;
            for (int i = 0; i < 16384; i++) {
                if (dp[i] != -1) {
                    ndp[i ^ x] = max(ndp[i ^ x], dp[i] + 1);
                }
            }
            dp = ndp;
        }

        if (dp[target] == -1)
            return -1;

        return n - dp[target];
    }
};
