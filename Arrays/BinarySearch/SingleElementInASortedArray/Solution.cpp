// Problem link : https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int l = 0, h = nums.size() - 1;
        while (l < h) {
            int mid = l + (h - l) / 2;

            bool isEven;
            if ((h - mid) % 2 == 0) {
                isEven = true;
            } else {
                isEven = false;
            }

            if (nums[mid] == nums[mid + 1]) {
                if (isEven) {
                    l = mid + 2;
                } else {
                    h = mid - 1;
                }
            } else {
                if (isEven) {
                    h = mid;
                } else {
                    l = mid + 1;
                }
            }
        }
        return nums[l];
    }
};
