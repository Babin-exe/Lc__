// Problem link: https://leetcode.com/problems/apply-operations-to-maximize-frequency-score/

  class Solution {

    public boolean isPossible(int len, int[] nums, long[] prefix, int n, long k) {

        int i = 0, j = len - 1;
        while (j < n) {

            int target_idx = i + (j - i) / 2;
            long target = nums[target_idx];

            long leftSum = (target_idx > 0 ? prefix[target_idx - 1] : 0) - (i > 0 ? prefix[i - 1] : 0);
            long rightSum = prefix[j] - prefix[target_idx];
            long left_opr = (long)(target_idx - i) * target - leftSum;
            long right_opr = rightSum - ((long)(j - target_idx) * target);

            if (left_opr + right_opr <= k)
                return true;

            i++;
            j++;

        }

        return false;
    }

    public int maxFrequencyScore(int[] nums, long k) {

        Arrays.sort(nums);
        int n = nums.length;
        int l = 1, r = n;
        int ans = 1;
        long[] pref = new long[n];
        pref[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(mid, nums, pref, n, k)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }

        }
        return ans;

    }
}
