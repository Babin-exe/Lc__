// Problem link : https://leetcode.com/problems/minimum-cost-to-make-array-equal/

class Solution {

    public long findCost(int[] nums, int[] cost, int c) {
        long ans = 0;
        for (int i = 0; i < nums.length; i++) {
            ans += (long) (Math.abs(nums[i] - c)) * cost[i];

        }
        return ans;
    }

    public long minCost(int[] nums, int[] cost) {
        int start = Arrays.stream(nums).min().getAsInt();
        int end = Arrays.stream(nums).max().getAsInt();
        long ans = Long.MAX_VALUE;
        while (start <= end) {

            int mid = start + (end - start) / 2;

            long cost_1 = findCost(nums, cost, mid);
            long cost_2 = findCost(nums, cost, mid + 1);

            ans = Math.min(cost_1, cost_2);

            if (cost_2 > cost_1) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }

        }
        return (ans == Long.MAX_VALUE) ? 0 : ans;
    }
}
