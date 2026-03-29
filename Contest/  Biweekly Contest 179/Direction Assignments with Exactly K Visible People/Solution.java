
class Solution {
    int MOD = 1000000007;

    long power(long x, long n) {
        if (n == 0)
            return 1;

        long val = power(x, n / 2) % MOD;
        long ans = val * val % MOD;

        if (n % 2 != 0) {
            ans = ans * x % MOD;
        }

        return ans;
    }

    long ncr(int n, int r) {

        if (r < 0 || r > n)
            return 0;

        if (r == 0)
            return 1;

        long num = 1, den = 1;
        r = Math.min(r, n - r);
        for (int i = 0; i < r; i++) {
            num = num * (n - i) % MOD;
            den = den * (i + 1) % MOD;
        }
        return 1L * num * power(den, MOD - 2) % MOD;
    }

    public int countVisiblePeople(int n, int pos, int k) {

        return (int) (2L * ncr(n - 1, k) % MOD);
    }
}
