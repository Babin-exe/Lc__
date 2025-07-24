// Problem link : https://leetcode.com/problems/k-radius-subarray-averages/description/


class Solution {
    public int[] getAverages(int[] nums, int k) {
        int n = nums.length;
        int size = 2 * k + 1;
        int[] result = new int[n];
        if (k == 0) {
            return nums;
        }
        if (n < size) {
            for (int i = 0; i < n; i++) {
                nums[i] = -1;

            }
            return nums;
        }

        for (int i = 0; i < n; i++) {
            result[i] = -1;
        }

        long sum = 0;
        for (int i = 0; i < size; i++) {
            sum += nums[i];
        }
        result[k] = (int) (sum / size);

        for (int i = k + 1; i < n - k; i++) {
            sum = sum - nums[i - k - 1] + nums[i + k];

            result[i] = (int) (sum / size);

        }
        return result;
    }
}
