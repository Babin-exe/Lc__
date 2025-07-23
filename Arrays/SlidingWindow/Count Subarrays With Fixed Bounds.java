Problem link : https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/

class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        int n = nums.length;
        int i = 0;
        long count = 0;
        long minindex = -1;
        long maxindex = -1;
        long invalid = -1;
        long temp;
        while (i < n) {
            if (nums[i] == minK) {
                minindex = i;
            }
            if (nums[i] == maxK) {
                maxindex = i;
            }
            if (nums[i] > maxK || nums[i] < minK) {
                invalid = i;
            }

            long smaller = Math.min(minindex, maxindex);
            temp = smaller - invalid;
            if (temp < 0) {
                count += 0;
            } else {
                count += temp;
            }
            i++;
        }

        return count;
    }
}
