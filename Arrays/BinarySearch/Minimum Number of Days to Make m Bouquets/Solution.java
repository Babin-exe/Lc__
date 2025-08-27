// Problem link : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

  class Solution {

    public boolean isPossible(int[] bloomDay, int target, int m, int k) {
        int flower_count = 0;
        int boq_count = 0;
        int n = bloomDay.length;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= target) {
                flower_count++;
            } else {
                flower_count = 0;
            }
            if (flower_count == k) {
                boq_count++;
                flower_count = 0;
            }
            if (boq_count == m)
                return true;
        }
        return false;
    }

    public int minDays(int[] bloomDay, int m, int k) {
        int n = bloomDay.length;
        if (n < m * k) {
            return -1;
        }

        int l = 1, r = Arrays.stream(bloomDay).max().getAsInt();
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(bloomDay, mid, m, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
}
