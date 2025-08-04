// Problem link : https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/1722474455/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;
        while (start <= end) {

            int mid = start + (end - start) / 2;
            if (arr[mid + 1] > arr[mid]) {

                start = mid + 1;
            } else {

                end = mid - 1;
            }
        }

        return start;
    }
};
