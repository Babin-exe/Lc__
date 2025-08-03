// Problem link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {

    public int auhNsk(int[] nums, int target, boolean findStart) {

        int anss = -1;
        int start = 0, end = nums.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                anss = mid;
                if (findStart) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }

        return anss;
    }

    public int[] Finder(int[] nums, int target) {
        int[] ans = { -1, -1 };
        ans[0] = auhNsk(nums, target, true);
        ans[1] = auhNsk(nums, target, false);
        return ans;
    }

    public int[] searchRange(int[] nums, int target) {
        return Finder(nums, target);

    }

}
