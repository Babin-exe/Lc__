// Problem link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    int auhNsk(const vector<int>& nums, int target, bool findStart) {
        int anss = -1;
        int start = 0, end = (int)nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                anss = mid;
                if (findStart) {
                    end = mid - 1;  
                } else {
                    start = mid + 1; 
                }
            }
        }
        return anss;
    }

    vector<int> Finder(const vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        ans[0] = auhNsk(nums, target, true);
        ans[1] = auhNsk(nums, target, false);
        return ans;
    }

    vector<int> searchRange(const vector<int>& nums, int target) {
        return Finder(nums, target);
    }
};
