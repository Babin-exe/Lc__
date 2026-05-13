// Problem Link : https://leetcode.com/problems/concatenate-array-with-reverse/

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int> t;
        for (int i = 0; i < n; ++i) {
            t.push_back(nums[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            t.push_back(nums[i]);
        }
        return t;
    }
};
