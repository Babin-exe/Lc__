// Problem Link : https://leetcode.com/problems/two-best-non-overlapping-events/description/
import java.util.*;

class Solution {
    int n;
    int[][] dp;

    int binarySearch(int[][] events, int endTime) {
        int l = 0, r = n - 1;
        int ans = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (events[mid][0] > endTime) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int solve(int[][] events, int i, int count) {
        if (i >= n || count == 2)
            return 0;

        if (dp[i][count] != -1)
            return dp[i][count];

        int take = events[i][2]
                + solve(events,
                        binarySearch(events, events[i][1]),
                        count + 1);

        int dontTake = solve(events, i + 1, count);

        return dp[i][count] = Math.max(take, dontTake);
    }

    public int maxTwoEvents(int[][] events) {
        n = events.length;

        Arrays.sort(events, (a, b) -> {
            if (a[0] != b[0])
                return a[0] - b[0];
            if (a[1] != b[1])
                return a[1] - b[1];
            return a[2] - b[2];
        });

        dp = new int[n][2];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }

        return solve(events, 0, 0);
    }
}
