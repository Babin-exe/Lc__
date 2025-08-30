// Problem link : https://leetcode.com/problems/most-beautiful-item-for-each-query/description/
class Solution {

    public int findAns(int querie, int[][] items) {

        int l = 0, r = items.length - 1;
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (items[mid][0] > querie) {

                r = mid - 1;

            } else if (items[mid][0] <= querie) {
                ans = items[mid][1];
                l = mid + 1;
            }

        }
        return ans;

    }

    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items, (a, b) -> a[0] - b[0]);
        int n = items.length;
        for (int i = 1; i < n; i++) {
            items[i][1] = Math.max(items[i - 1][1], items[i][1]);
        }

        int[] ans = new int[queries.length];

        for (int i = 0; i < queries.length; i++) {
            ans[i] = findAns(queries[i], items);
        }
        return ans;
    }
}
