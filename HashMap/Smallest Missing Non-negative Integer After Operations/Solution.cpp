// Problem Link : https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        unordered_map<int, int> mp;

        for (int& take : nums) {
            int v = ((take % value) + value) % value;
            mp[v]++;
        }
        int mexi = 0;
        while (mp[mexi % value] > 0) {
            mp[mexi % value]--;
            mexi++;
        }
        return mexi;
    }
};
