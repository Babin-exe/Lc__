// Problem link : https://leetcode.com/problems/minimum-time-to-complete-trips/
class Solution {

    public boolean auhNsk(int[] time, long mid, int totalTrips) {
        long sum = 0;
        for (int a : time) {
            sum += (mid / a);
        }
        return sum >= totalTrips;
    }

    public long minimumTime(int[] time, int totalTrips) {
        long i = 1, j = (long) Arrays.stream(time).min().getAsInt() * totalTrips;

        while (i < j) {

            long mid = i + (j - i) / 2;
            if (auhNsk(time, mid, totalTrips)) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return i;

    }

}
