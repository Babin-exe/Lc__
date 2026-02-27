// Problem Link :https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0]++;
        int n = nums.size();
        int pref = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            pref += nums[i];
            int val = pref - k;
            auto it = mp.find(val);
            if (it != mp.end()) {
                ans += (it->second);
            }
            mp[pref]++;
        }
        return ans;
    }
};
