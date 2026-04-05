// Problem Link : https://leetcode.com/problems/minimum-removals-to-achieve-target-xor/

class Solution {
    public int minRemovals(int[] nums, int target) {
        int maxi = 16384;
        int[] dp = new int[maxi];
        dp[0] = 0;
        for (int i = 1; i < maxi; i++)
            dp[i] = -1;
        int n = nums.length;
        for (int x : nums) {
            int[] ndp = dp.clone();
            for (int i = 0; i < maxi; i++) {
                if (dp[i] != -1)
                    ndp[i ^ x] = Math.max(ndp[i ^ x], dp[i] + 1);
            }
            dp = ndp;
        }
        if (dp[target] == -1)
            return -1;

        return n - dp[target];
    }
}
