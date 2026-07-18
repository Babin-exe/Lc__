// Problem Link : https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        unordered_map<int, int> mp;
        mp[0]++;
        vector<int> ps(n);
        ps[0] = nums[0];
        mp[((nums[0] % k) + k) % k]++;
        ans = nums[0] % k == 0 ? 1 : 0;

        for (int i = 1; i < n; i++) {
            ps[i] = nums[i] + ps[i - 1];
            int m = ((ps[i] % k) + k) % k;

            ans += mp[m];
            mp[m]++;
        }

        return ans;
    }
};
