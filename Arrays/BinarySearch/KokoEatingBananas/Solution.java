// Problem link : https://leetcode.com/problems/koko-eating-bananas/
class Solution {

    public boolean hehe(int[] piles, int mid, int h) {
        int sum = 0;
        for (int take : piles) {

            sum += (take + mid - 1) / mid;
        }
        return sum <= h;
    }

    public int minEatingSpeed(int[] piles, int h) {

        int i = 1, j = Arrays.stream(piles).max().getAsInt();

        while (i < j) {
            int mid = i + (j - i) / 2;
            if (hehe(piles, mid, h)) {
                j = mid;
            } else {
                i = mid + 1;
            }

        }
        return i;
    }
}
