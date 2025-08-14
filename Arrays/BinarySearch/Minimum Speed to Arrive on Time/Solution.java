// Problem link : https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
class Solution {

    public boolean auhNsk(int[] dist, int mid, double hour) {
        double ans = 0;
        for (int i = 0; i < dist.length - 1; i++) {

            ans += Math.ceil(dist[i] / (double) mid);
        }
        ans += dist[dist.length - 1] / (double) mid;

        return ans <= hour;
    }

    public int minSpeedOnTime(int[] dist, double hour) {
        int l = 1, r = (int) 1e7;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (auhNsk(dist, mid, hour)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }

        }
        return ans;
    }
}
