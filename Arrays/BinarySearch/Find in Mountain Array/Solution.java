// Problem link :  https://leetcode.com/problems/find-in-mountain-array/


/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */

class Solution {

    public int binarySearch(MountainArray mountainArr, int target, int l, int r, boolean inc)

    {

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int take = mountainArr.get(mid);
            if (inc) {

                if (take == target) {
                    return mid;
                } else if (take > target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (take == target) {
                    return mid;
                } else if (take < target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }

    public int findPivot(MountainArray mountainArr) {
        int l = 0, r = mountainArr.length() - 1;
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

    public int findInMountainArray(int target, MountainArray mountainArr) {

        int pivot = findPivot(mountainArr);
        int ans = -1;

        if (mountainArr.get(pivot) == target) {
            return pivot;
        }
        ans = binarySearch(mountainArr, target, 0, pivot - 1, true);
        if (ans != -1) {
            return ans;
        }

        return binarySearch(mountainArr, target, pivot + 1, mountainArr.length() - 1, false);

    }
}
