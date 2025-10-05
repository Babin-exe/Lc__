// Problem Link : https://leetcode.com/problems/water-bottles/description/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int mod = 0;
        int div = 0;
        int n = numBottles;

        while (n != 0) {
            div = (n / numExchange);
            if (div == 0)
                break;
            ans += div;
            mod = n % numExchange;
            n = div + mod;
        }
        return ans + numBottles;
    }
};
