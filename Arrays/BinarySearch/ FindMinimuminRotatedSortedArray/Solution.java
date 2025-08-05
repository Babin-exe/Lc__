// Problem link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {

    public int finder(int[] nums) {
        int start = 0, end = nums.length - 1;
        int ans = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mid < end && nums[mid] > nums[mid + 1]) {
                return mid + 1;
            } else if (start < mid && nums[mid - 1] > nums[mid]) {
                return mid;
            }
            if (nums[0] < nums[mid]) {

                start = mid + 1;
            } else {
                end = mid - 1;
            }

        }
        return 0;
    }

    public int findMin(int[] nums) {
        int index = finder(nums);
        return nums[index];
    }
}
