// Problem Link : https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/


class Solution {
public:
    int solve(long curr, long next, int n) {
        int ans = 0;
        while (curr <= n) {
            ans += (next - curr);
            curr *= 10;
            next *= 10;
            next = min(next, (long)n + 1);
        }
        return ans;
    }

public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {

            int hehe = solve(curr, curr + 1, n);

            if (hehe <= k) {
                curr++;
                k -= hehe;
            } else {
                k--;
                curr *= 10;
            }
        }

        return curr;
    }
};
