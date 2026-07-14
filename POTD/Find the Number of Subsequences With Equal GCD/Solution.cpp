// Problem Link : https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/description/?envType=daily-question&envId=2026-07-14
class Solution {
public:
    int n;
    int dp[201][201][201];
    const int MOD = 1e9 + 7;

    int solve(vector<int>& nums, int i, int gcd1, int gcd2) {
        if (i == n) {
            bool gcd = (gcd1 != 0 && gcd2 != 0);
            bool equal = (gcd1 == gcd2);

            return (gcd && equal) ? 1 : 0;
        }

        if (dp[i][gcd1][gcd2] != -1)
            return dp[i][gcd1][gcd2];

        int skip = solve(nums, i + 1, gcd1, gcd2);
        int seq1 = solve(nums, i + 1, __gcd(nums[i], gcd1), gcd2);
        int seq2 = solve(nums, i + 1, gcd1, __gcd(nums[i], gcd2));

        return dp[i][gcd1][gcd2] = (0LL + skip + seq1 + seq2) % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        // nums , index , gcd1 , gcd2
        memset(dp, -1, sizeof(dp));

        return solve(nums, 0, 0, 0);
    }
};
