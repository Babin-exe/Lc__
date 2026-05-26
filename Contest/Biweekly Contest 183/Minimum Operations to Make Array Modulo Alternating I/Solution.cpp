// Problem Link : https://leetcode.com/problems/minimum-operations-to-make-array-modulo-alternating-i/description/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int c = INT_MAX;
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                int ct = 0;
                if (x == y)
                    continue;
                for (int i = 0; i < n; i++) {
                    int target = (i % 2 == 0 ? x : y);
                    int current = nums[i] % k;
                    int front = (target - current + k) % k;
                    int back = (current - target + k) % k;

                    ct += min(front, back);
                }
                c = min(c, ct);
            }
        }
        return c;
    }
};
