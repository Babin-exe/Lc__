class Solution {
public:
    bool isValid(const vector<int> &nums, int mid_max, int n) {
        vector<long long> arr(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > mid_max) return false;
            long long buffer = mid_max - arr[i];
            arr[i + 1] -= buffer;
        }
        return arr[n - 1] <= mid_max;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (int x : nums) sum += x;

        int maxL = (sum + n - 1) / n;
        int maxR = *max_element(nums.begin(), nums.end());
        int result = maxR;

        while (maxL <= maxR) {
            int mid_max = maxL + (maxR - maxL) / 2;
            if (isValid(nums, mid_max, n)) {
                result = mid_max;
                maxR = mid_max - 1;
            } else {
                maxL = mid_max + 1;
            }
        }
        return result;
    }
};
