// Problem Link : https://leetcode.com/problems/count-number-of-trapezoids-i/description/

class Solution {
    HashMap<Integer, Integer> mp = new HashMap<>();
    long sum = 0;
    long prev = 0;
    int MOD = 1_000_000_007;

    public int solve(int[][] points) {
        for (int[] val : points) {
            int take = val[1];
            mp.put(take, mp.getOrDefault(take, 0) + 1);
        }

        for (Map.Entry<Integer, Integer> take : mp.entrySet()) {
            int t = take.getValue();
            long comb = (long) t * (t - 1) / 2;
            sum += ((comb * prev) % MOD);
            prev += comb;
        }
        return (int) (sum % MOD);

    }

    public int countTrapezoids(int[][] points) {
        return solve(points);
    }
}
