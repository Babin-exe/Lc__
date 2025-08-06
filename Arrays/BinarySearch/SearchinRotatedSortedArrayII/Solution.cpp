// Problem link : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
class Solution {

public:
    bool binarySearch(vector<int>& nums, int target, int start, int end) {

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }

public:
    int findPivot(vector<int>& nums, int start, int end) {

        while (start < end) {

            while (end > start && nums[start] == nums[start + 1])
                start++;

            while (end > start && nums[end] == nums[end - 1])
                end--;

            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }

public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums, 0, n - 1);

        if (pivot == -1) {
            return binarySearch(nums, target, 0, n - 1);
        }
        if (nums[pivot] == target) {

            return true;
        }

        if (binarySearch(nums, target, 0, pivot - 1)) {

            return true;
        }

        return binarySearch(nums, target, pivot, n - 1);
    }
};
