// Problem Link : https://leetcode.com/contest/weekly-contest-470/problems/longest-subsequence-with-non-zero-bitwise-xor/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool allZero = true;
        int value = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {

            value ^= nums[i];

            if (nums[i] != 0)
                allZero = false;
        }
        if (value != 0)
            return n;
        if (!allZero)
            return n - 1;
        else
            return 0;
    }
};
