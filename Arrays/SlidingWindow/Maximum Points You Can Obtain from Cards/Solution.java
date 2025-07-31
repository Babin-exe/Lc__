// Problem link : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
// Time complexity : O(k);
// Space Complexity : O(1);


class Solution {
    public int maxScore(int[] cardPoints, int k) {

        int maxi = 0;
        int sum = 0;
        int n = cardPoints.length;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        maxi = sum;

        int idx = n - 1;
        for (int i = k - 1; i >= 0; i--) {

            sum -= cardPoints[i];
            sum += cardPoints[idx--];
            maxi = Math.max(maxi, sum);
        }

        return maxi;
    }
}
