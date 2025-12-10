// Problem Link :https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/

class Solution {
    int mod = 1_000_000_007;

    public long factorial(long n) {
        long hehe = 1;
        for (int i = 1; i <= n; i++) {
            hehe = (hehe * i) % mod;
        }
        return hehe;
    }

    public int countPermutations(int[] complexity) {
        int n = complexity.length;
        for (int i = 1; i < n; i++) {
            if (complexity[0] >= complexity[i])
                return 0;
        }

        long ans = factorial(n - 1) % mod;
        return (int) ans;
    }
}
