// Problem link : https://leetcode.com/problems/count-the-number-of-fair-pairs/

class Solution {

public:
    int lowerFind(int target, vector<int>& nums, int lower, int upper) {
        int l = 0, r = nums.size() - 1;
        int ans = nums.size();
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (target + nums[mid] >= lower) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

public:
    int upperFind(int target, vector<int>& nums, int lower, int upper) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target + nums[mid] <= upper) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        sort(begin(nums), end(nums));
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int left_val = lowerFind(nums[i], nums, lower, upper);
            int right_val = upperFind(nums[i], nums, lower, upper);

            ans += right_val - left_val + 1;
           if(i>=left_val && i<=right_val)ans--;
        }
        return ans / 2;
    }
};
