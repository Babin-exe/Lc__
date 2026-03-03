// Problem Link : https://leetcode.com/problems/smallest-pair-with-different-frequencies/description/

class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        unordered_map<int, int> mp;
        for (auto& it : nums) {
            mp[it]++;
        }
        vector<int> ans;
        ans.push_back(nums[0]);
        bool hehe = false;
        for (int i = 1; i < n; i++) {
            if (nums[i] != ans[0] && mp[nums[0]] != mp[nums[i]]) {
                ans.push_back(nums[i]);
                hehe = true;
                break;
            }
        }
        if (hehe)
            return ans;

        return {-1, -1};
    }
};
