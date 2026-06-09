// Problem Link : https://leetcode.com/problems/maximum-total-subarray-value-i/description/?envType=daily-question&envId=2026-06-09
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxi)
                maxi = nums[i];
            if (nums[i] < mini)
                mini = nums[i];
        }
        return (maxi - mini) * 1LL * k;
    }
};
