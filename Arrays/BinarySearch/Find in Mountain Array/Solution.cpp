//Problem link : https://leetcode.com/problems/find-in-mountain-array/submissions/1742705232/
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {

public:
    int findPivot(MountainArray& mountainArr, int end) {
        int l = 0, r = end;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) > mountainArr.get(mid + 1)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

public:
    int binarySearch(MountainArray& mountainArr, int target, int l, int r,
                     bool asc) {

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mountainArr.get(mid);
            if (asc) {
                if (val == target) {
                    return mid;
                } else if (val > target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {

                if (val == target) {
                    return mid;
                } else if (val < target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }

public:
    int findInMountainArray(int target, MountainArray& mountainArr) {

        int size = mountainArr.length();
        int pivot = findPivot(mountainArr,  size - 1);

        int ans = -1;
        if (mountainArr.get(pivot) == target)
            return pivot;

        ans = binarySearch(mountainArr, target, 0, pivot - 1, true);
        if (ans != -1)
            return ans;

        return binarySearch(mountainArr, target, pivot + 1, size - 1, false);
    }
};
