// Problem link : https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
    public int minSubArrayLen(int target, int[] nums) {

        int i = 0, j = 0;
        int n = nums.length;
        int sum = 0;
        int sub = Integer.MAX_VALUE;

        while (j < n) {
            sum += nums[j];
            while (sum >= target) {
                sub = Math.min(sub, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return sub == Integer.MAX_VALUE ? 0 : sub;
    }
}
