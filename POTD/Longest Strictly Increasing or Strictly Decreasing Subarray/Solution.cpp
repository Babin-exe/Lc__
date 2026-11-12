// Problem Link : https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1, dec = 1, ans = 1;

        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] > nums[i]) {
                dec++;
                ans = max(ans, dec);
                inc = 1;

            } else if (nums[i] > nums[i - 1]) {
                dec = 1;
                inc++;
                ans = max(ans, inc);
            } else {
                inc = 1;
                dec = 1;
            }
        }

        return ans;
    }
};
