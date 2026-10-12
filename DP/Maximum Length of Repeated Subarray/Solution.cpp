// Problem Link : https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(1001, vector<int>(1001, 0));

        int n = nums1.size();
        int m = nums2.size();

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
            }
        }

        int maxi = 0;
        for (int i = 1; i < 1001; ++i) {
            for (int j = 1; j < 1001; ++j) {
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi;
    }
};
