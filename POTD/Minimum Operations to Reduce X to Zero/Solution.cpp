// Problem Link : https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int total = accumulate(begin(nums), end(nums), 0);
        int n = nums.size();

        int rem = total - x;

        if (rem < 0) return -1;
        if (rem == 0) return n;

        int i = 0, j = 0;
        int len = -1;
        int sum = 0;

        while (i < n && j < n) {

            sum += nums[j];

            while (i <= j && sum > rem) {
                sum -= nums[i];
                i++;
            }

            if (sum == rem) {
                len = max(len, j - i + 1);
            }

            j++;
        }
        return len == -1 ? -1 : n - len;
    }
};
