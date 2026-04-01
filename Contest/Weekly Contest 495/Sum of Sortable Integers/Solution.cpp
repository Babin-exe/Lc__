// Problem Link : https://leetcode.com/problems/sum-of-sortable-integers/description/

class Solution {
public:
    bool solve(vector<int>& nums, int k, int n) {
        int prev = -1;
        for (int i = 0; i < n; i += k) {

            int mini = nums[i], maxi = nums[i];
            int ct = 0;

            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] > nums[j + 1])
                    ct++;
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
            }

            mini = min(mini, nums[i + k - 1]);
            maxi = max(maxi, nums[i + k - 1]);

            if (ct == 0) {
            } else if (ct == 1) {
                if (nums[i] < nums[i + k - 1])
                    return false;
            } else {
                return false;
            }

            if (prev > mini)
                return false;

            prev = maxi;
        }
        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i != 0)
                continue;

            if (solve(nums, i, n))
                sum += i;
        }

        return sum;
    }
};
