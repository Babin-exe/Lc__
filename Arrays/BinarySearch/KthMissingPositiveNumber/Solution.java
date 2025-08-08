// Problem link https://leetcode.com/problems/kth-missing-positive-number/

class Solution {
    public int findKthPositive(int[] nums, int k) {
        // This is the linear approach
        //     int j = 0;
        //     int num = 1;
        //     while (j < nums.length && k > 0) {

        //         if (nums[j] == num) {
        //             j++;
        //         } else {

        //             k--;
        //         }
        //         num++;

        //     }
        //     while (k-- > 0) {
        //         num++;
        //     }
        //     return num - 1;

        // }

        //Lets try the binary search approach :)

        int start = 0, end = nums.length - 1, n = nums.length;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            int missing = nums[mid] - (mid + 1);
            if (missing < k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }

        }
        return start + k;

    }
}
