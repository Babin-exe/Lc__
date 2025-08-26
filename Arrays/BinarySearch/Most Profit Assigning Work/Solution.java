// Problem link : https://leetcode.com/problems/most-profit-assigning-work/description/

class Solution {

    public int binarySearch(int[][] stuff, int target) {

        int l = 0, r = stuff.length - 1;
        int id = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (stuff[mid][0] <= target) {
                id = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return id;
    }

    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {

        int n = difficulty.length;
        Arrays.sort(worker);

        int[][] stuff = new int[n][2];
        for (int i = 0; i < n; i++) {

            stuff[i][0] = difficulty[i];

            stuff[i][1] = profit[i];

        }

        Arrays.sort(stuff, (a, b) -> a[0] - b[0]);

        for (int i = 1; i < n; i++) {
            stuff[i][1] = Math.max(stuff[i - 1][1], stuff[i][1]);
        }
        int ans = 0;
        int m = worker.length;
        for (int i = 0; i < m; i++) {
            int idx = binarySearch(stuff, worker[i]);
            if (idx != -1)
                ans += stuff[idx][1];

        }

        return ans;
    }
}
