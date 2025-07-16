// Problem Link : https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/description/?envType=daily-question&envId=2025-07-16


class Solution {
    public int maximumLength(int[] nums) {
        int evenCount = 0;
        int oddCount = 0;
        int alter = 1;
        int parity = nums[0] % 2;
        for (int hehe : nums) {
            int auh = hehe%2;
            if (hehe % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
            if (auh != parity) {
                parity = auh;
                alter++;
            }
        }

        return Math.max(evenCount, Math.max(oddCount, alter));

    }
}
