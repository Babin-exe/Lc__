// Problem Link : https://leetcode.com/problems/power-of-two/description/
class Solution {
    public boolean isPowerOfTwo(int n) {
        if (n == 0)
            return false;
        if (n < 0)
            return false;
        return (n & (n - 1)) == 0;
    }
}
