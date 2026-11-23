// Problem Link : https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<int> dp(nums.back() + 2, 0);
        int ans = 1;
        for (auto it : nums) {
            dp[it + 1] = dp[it] + 1; dp[it] = dp[it - 1] + 1;
             ans = max({ans, dp[it + 1], dp[it]});
        }
        return ans;
    }
};
