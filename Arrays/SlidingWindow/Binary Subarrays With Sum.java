// Problem link : https://leetcode.com/problems/binary-subarrays-with-sum/description/


class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {

        int i = 0, j = 0;
        int n = nums.length;
        int sum = 0;
        int sub = 0;
        int zero_num = 0;
        while (j < n) {
            sum += nums[j];

            while (i < j && ((sum > goal) || nums[i] == 0)) {
                sum = sum - nums[i];

                if (nums[i] == 0) {
                    zero_num++;
                } else {
                    zero_num = 0;
                }
                i++;
            }

            if (sum == goal) {
                sub = sub + 1 + zero_num;

            }
            j++;
        }
        return sub;
    }
}
