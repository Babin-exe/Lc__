// Problem Link : https://leetcode.com/problems/maximum-alternating-sum-of-squares/
using ll = long long;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size();
        for (int i = 0; i < n; ++i)nums[i] *= nums[i];

        sort(begin(nums), end(nums));

        ll sum = 0;
        int mid = n / 2;

        for (int i = n - 1; i >= mid; --i) sum += nums[i];
        for (int i = mid - 1; i >= 0; --i) sum -= nums[i];

        return sum;
    }
};
