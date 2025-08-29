// Problem link : https://leetcode.com/problems/magnetic-force-between-two-balls/
class Solution {

    public boolean isPossible(int[] position, int target, int m) {
        int current = position[0];
        int value = 1;

        for (int i = 1; i < position.length; i++) {
            int take = position[i];
            if ((take - current) >= target) {
                value++;
                current = take;

            }

            if (value == m)
                break;
        }
        return value == m;
    }

    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        int n = position.length;
        int l = 1, r = position[n - 1] - position[0];
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(position, mid, m)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;

    }
}
