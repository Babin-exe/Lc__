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









/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    int find_pivot(vector<int>& nums, int l, int r) {
        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return r;
    }

    int binary_search(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = find_pivot(nums, 0, n - 1);

        if (nums[pivot] == target)
            return pivot;

        int idx = -1;
        idx = binary_search(nums, pivot + 1, n - 1, target);
        if (idx != -1)
            return idx;
        idx = binary_search(nums, 0, pivot - 1, target);
        return idx;
    }
};



