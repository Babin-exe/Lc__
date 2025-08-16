// Problem link : https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/
class Solution {

    public boolean auhNsk(int p, int[] nums, int mid) {

        int left = 0, right = nums.length - 1;
        int ans = 0;
        while (left < right) {
            if (nums[left + 1] - nums[left] <= mid) {
                left += 2;
                if (ans >= p) return true;
                ans++;
            } else {
                left++;
            }
        }
        return ans >= p;
    }

    public int minimizeMax(int[] nums, int p) {
        Arrays.sort(nums);
        int left = 0;
        int right = nums[nums.length - 1] - nums[0];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (auhNsk(p , nums , mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }
}
