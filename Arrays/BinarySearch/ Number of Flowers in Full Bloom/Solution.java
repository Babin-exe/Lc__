// Pronblem link : https://leetcode.com/problems/number-of-flowers-in-full-bloom/
class Solution {
    public int[] fullBloomFlowers(int[][] flowers, int[] people) {

        int n = flowers.length;
        int m = people.length;

        int[] start = new int[n];
        int[] ends = new int[n];
        for (int i = 0; i < n; i++) {
            start[i] = flowers[i][0];
            ends[i] = flowers[i][1];
        }

        Arrays.sort(start);
        Arrays.sort(ends);

        int[] ans = new int[m];

        for (int i = 0; i < m; i++) {

            int t = people[i];
            int flower_bloom = bloomedFlower(start, t);
            int flower_gone = goneFlower(ends, t);

            ans[i] = (flower_bloom - flower_gone);

        }
        return ans;

    }

    public int bloomedFlower(int[] arr, int target) {
        int l = 0, r = arr.length;
        while (l < r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }

        }
        return l;
    }

    public int goneFlower(int[] arr, int target) {

        int l = 0, r = arr.length;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;

    }

}
