// Problem link : https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/submissions/1731952184/

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int i = 1, j = maxSum;
        int ans = 0;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (auhNsk(n, index, maxSum, mid)) {
                ans = mid;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return ans;
    }

public:
    bool auhNsk(int n, int index, int maxSum, int mid) {

        long long ans = 0;
        long long left_num = index;
        long long right_num = n - 1 - index;
        long long peak = mid - 1;
        long long left_sum = 0;
        long long right_sum = 0;
        if (peak > left_num) {
            left_sum = ((2L * mid - 1 - left_num) * left_num) / 2;
        } else {
            left_sum = ((long)mid * (mid - 1) / 2) + (left_num - (mid - 1));
        }

        if (peak > right_num) {

            right_sum = ((2L * mid - 1 - right_num) * right_num) / 2;

        } else {
            right_sum = ((long)mid * (mid - 1) / 2) + (right_num - (mid - 1));
        }

        ans = left_sum + right_sum + mid;

        return ans <= maxSum;
    }
};
