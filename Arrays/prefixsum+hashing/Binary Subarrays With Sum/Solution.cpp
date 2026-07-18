// Problem Link : https://leetcode.com/problems/binary-subarrays-with-sum/description/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ps(n);
        ps[0] = nums[0];
        unordered_map<int, int> mp;
        mp[0]++;
        mp[nums[0]]++;
        int ans = 0;

        ans = nums[0] == k ? 1 : 0;

        for (int i = 1; i < n; i++) {
            ps[i] = nums[i] + ps[i - 1];

            ans += mp[ps[i] - k];
            mp[ps[i]]++;
        }

        return ans;
    }
};
