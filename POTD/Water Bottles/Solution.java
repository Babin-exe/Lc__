// https://leetcode.com/problems/water-bottles/
class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int n = numBottles;
        int mod = 0;
        int val = 0;
        while (n != 0) {
            val = (n / numExchange);
            if (val == 0)
                break;
            ans += val;

            mod = n % numExchange;
            n = mod + val;

        }
        return ans + numBottles;
    }
}
