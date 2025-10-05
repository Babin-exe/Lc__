// Problem Link : https://leetcode.com/contest/weekly-contest-470/problems/compute-alternating-sum/
class Solution {
    public int alternatingSum(int[] nums) {
        int even_sum = 0;
        int odd_sum = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i % 2 == 0)
                even_sum += nums[i];
            if (i % 2 != 0)
                odd_sum += nums[i];
        }
        return (even_sum - odd_sum);

    }
}
