// Problem link : https://leetcode.com/problems/maximum-running-time-of-n-computers/
class Solution {

    public boolean possible(int[] batteries, long mid, int n) {
        long target_min = n * mid;
        for (int i = 0; i < batteries.length; i++) {
            //You have to take the min to 
            //make sure that result gained wil not 
            //inflated 
            //[10,0] this might look like it work but second is 0
            //so instant death so we take min that will be Min(10,mid) 
            //this will make sure the answer is not possible

            target_min -= (Math.min(batteries[i], mid));
            if (target_min <= 0) {
                return true;
            }
        }
        return false;
    }

    public long maxRunTime(int n, int[] batteries) {
//we take the min as lower bound because that is the for sure minutes we get
        long l = (long) Arrays.stream(batteries).min().getAsInt();

        long r;
        long total_sum = 0;
        long ans = 0;
        for (int take : batteries) {

            total_sum += take;
        }
        r = total_sum / n;

        long result = 0;
        while (l <= r) {

            long mid = l + (r - l) / 2;
            if (possible(batteries, mid, n)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }

        }
        return ans;
    }
}