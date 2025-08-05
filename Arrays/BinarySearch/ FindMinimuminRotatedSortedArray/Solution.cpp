// Problem link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {

public:
    int binarySearch(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (start < mid && nums[mid] < nums[mid - 1]) {
                return mid;
            } else if (end > mid && nums[mid] > nums[mid + 1]) {
                return mid + 1;
            }
            if (nums[start] < nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return 0;
    }

public:
    int findMin(vector<int>& nums) { return nums[binarySearch(nums)]; }
};
