// Problem link: https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int i = 0, j = 0;
        int prev_count = 0;
        int odd_count = 0;
        int result = 0;
        int n = nums.length;

        while (j < n) {

            //first we count if the incoming is odd
            if (nums[j] % 2 != 0) {
                odd_count++;
                prev_count = 0;
            }
            //now we check if we have a valid window 
            // if we have it we increase our 
            //counter and try to shrink the window
            while (odd_count == k) {
                prev_count++;
                if (nums[i] % 2 == 1) {
                    odd_count--;
                }
                i++;

            }
            result += prev_count;
            j++;

        }
        return result;
    }
}
