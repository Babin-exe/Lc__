// Problem Link : https://leetcode.com/contest/weekly-contest-470/problems/longest-subsequence-with-non-zero-bitwise-xor/

class Solution {
    public int longestSubsequence(int[] nums) {

        int n = nums.length;
        if (n == 0)
            return 0;

        int xor = 0;
        boolean hehe = false;
        for (int num : nums) {
            xor ^= num;
            if (num != 0) {
                hehe = true;
            }
        }

        if (xor != 0)
            return n;

        if (hehe)
            return n - 1;
        else
            return 0;
    }
}
