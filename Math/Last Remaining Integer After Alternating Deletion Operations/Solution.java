// Problem Link : https://leetcode.com/problems/last-remaining-integer-after-alternating-deletion-operations/description/
class Solution {
    public long lastInteger(long n) {
        long a = 1;
        long d = 1;
        long turn = 0;
        while (true) {
            long l = ((n - a) / d) + 1;
            if (l == 1)
                break;
            if (turn % 2 == 1 && l % 2 == 0)
                a+= d;

            d *= 2;
            turn++;

        }
        return a;
    }
}
