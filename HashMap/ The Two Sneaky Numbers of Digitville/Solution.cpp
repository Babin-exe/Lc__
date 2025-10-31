// Problem Link : https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (auto& a : mp) {
            int key = a.first;
            int val = a.second;
            if (val == 2) {
                ans.push_back(key);
            }
        }
        return ans;
    }
};
