// Problem link : https://leetcode.com/problems/count-the-number-of-fair-pairs/

class Solution {

    public int leftSearch(int[] nums, int target, int lower, int upper) {

        int l = 0, r = nums.length - 1;
        int ans = nums.length;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] + target >= lower) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }

        }
        return ans;
    }

    public int rightSearch(int[] nums, int target, int lower, int upper) {
        int l = 0, r = nums.length - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] + target <= upper) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;

    }

    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        long ans = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {

            int left = leftSearch(nums, nums[i], lower, upper);
            int right = rightSearch(nums, nums[i], lower, upper);

            if (right >= left) {
                ans += (right - left + 1);
                if (i >= left && i <= right) {
                    ans--;
                }
            }

        }
        return ans / 2;
    }
}
