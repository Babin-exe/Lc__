// Problem Link : https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/

class Solution {
    public int solve(long curr, long next, int n) {
        int ans = 0;
        while (curr <= n) {
            ans += (next - curr);
            curr *= 10;
            next *= 10;
            next = Math.min(next, n + 1);
        }
        return ans;
    }

    public int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {

            int value = solve(curr, curr + 1, n);

            if (value <= k) {
                curr++;
                k -= value;
            } else {
                k--;
                curr *= 10;
            }
        }
        return curr;
    }
}
