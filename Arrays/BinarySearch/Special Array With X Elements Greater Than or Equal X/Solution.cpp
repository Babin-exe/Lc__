// Problem link: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

class Solution {

public:
    bool binarySearch(vector<int>& nums, int target, int n) {
        int l = 0, r = n - 1;
        while (l <= r) {

            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {

                if (n - mid == target) {
                    if (mid > 0 && nums[mid - 1] >= target)
                        return false;
                    return true;
                } else {
                    r = mid - 1;
                }

            } else {
                l = mid + 1;
            }
        }
        return false;
    }

public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i<=n;i++) {
            if (binarySearch(nums, i, n)) {
                return i;
            }
        }
        return -1;
    }
};
