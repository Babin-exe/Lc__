// Problem Link : https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

class Solution {
    public int minCost(String colors, int[] neededTime) {

        int n = neededTime.length;
        int sum = 0;
        int max = 0;
        int i = 0, j = 0;
        while (i < n && j < n) {
            if (colors.charAt(i) == colors.charAt(j)) {
                sum += neededTime[j];
                max = Math.max(max, neededTime[j]);
                j++;

            } else {
                sum -= max;
                max = -1;
                i = j;

            }
        }
        sum -= max;
        return sum;
    }
}
