// Problem Link : https://leetcode.com/problems/limit-occurrences-in-sorted-array/

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int t : nums)
            mp[t]++;

        vector<int> ans;

        for (auto& it : mp) {
            int ke = it.first;
            int v = it.second;

            if (v > k) {
                v = k;
            }

            while (v--) {
                ans.push_back(ke);
            }

        }
        return ans;
    }
};
