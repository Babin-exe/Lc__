// Problem link : https://leetcode.com/problems/search-in-rotated-sorted-array/description/


class Solution {

public:
    int binarySearch(vector<int>& nums, int target, int start, int end) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

public:
    int findPivot(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int pivot = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid < end && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (start < mid && nums[mid] < nums[mid - 1]) {
                return mid - 1;
            }
            if (nums[start] <= nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return pivot;
    }

public:
    int search(vector<int>& nums, int target) {

        int pivot = findPivot(nums, target);
        if (pivot == -1) {
            return binarySearch(nums, target, 0, nums.size() - 1);
        }
        if (nums[pivot] == target) {

            return pivot;
        }

        if (nums[0] <= target) {

            return binarySearch(nums, target, 0, pivot - 1);
        }
        return binarySearch(nums, target, pivot + 1, nums.size() - 1);
    }
};
