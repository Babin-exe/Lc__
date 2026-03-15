// Problem Link : https://leetcode.com/problems/minimum-cost-to-equalize-arrays-using-swaps/

class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mp;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            mp[nums1[i]]++;
            mp[nums2[i]]--;
        }
        int sum = 0;

        for (auto& [key, val] : mp) {
            if (val % 2 != 0)
                return -1;
            if (val > 0)
                sum += val / 2;
        }
        return sum;
    }
};
