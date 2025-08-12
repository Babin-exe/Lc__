// Problem link : https://leetcode.com/problems/minimize-maximum-of-array/\


class Solution {
    public boolean isValid(int[] nums, int target) {
        long[] arr = new long[nums.length];
        for (int i = 0; i < nums.length; i++) {
            arr[i] = nums[i];
        }

        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] > target) return false;
            long buffer = target - arr[i];
            arr[i + 1] -= buffer; 
        }

        return arr[arr.length - 1] <= target;
    }

    public int minimizeArrayValue(int[] nums) {
        int left = 0;
        int right = Arrays.stream(nums).max().getAsInt();
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(nums, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
}
