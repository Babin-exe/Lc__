// Problem Link : https://leetcode.com/problems/maximum-valid-pair-sum/description/
class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> smax(n);
        smax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            smax[i] = max(nums[i], smax[i + 1]);
        }
        int ans = 0;
        for (int i = 0; i < n - k; i++) {
            ans = max(ans, nums[i] + smax[i + k]);
        }
        return ans;
    }
};
