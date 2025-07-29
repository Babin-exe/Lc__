// Problem link : https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
        int result = 0, prev_idx = 0;
        int count = 0;

        while (j < n) {

            if (nums[j] % 2 != 0) {
                count++;
                prev_idx = 0;
            }

            while (count == k) {
                prev_idx++;
                if (nums[i] % 2 == 1) {
                    count--;
                }
                i++;
            }
            result += prev_idx;
            j++;
        }
        return result;
    }
};
