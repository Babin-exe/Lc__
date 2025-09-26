// Problem link : https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/

class Solution {
    int MOD = 1_000_000_007;

    public int numberOfWays(String corridor) {
        int n = corridor.length();
        int total = 0;
        long ans = 1;
        int sCount = 0;
        int prev_index = -1;
        for (int i = 0; i < n; i++) {
            char ch = corridor.charAt(i);
            if (ch == 'S') {
                sCount++;
                total++;
                if (sCount == 1 && prev_index != -1) {
                    ans = (ans * 1L * (i - prev_index)) % MOD;
                }
                if (sCount == 2) {
                    prev_index = i;
                    sCount = 0;
                }
            }
        }
        if (total == 0 || total % 2 != 0)
            return 0;

        return (int) ans;
    }
}
