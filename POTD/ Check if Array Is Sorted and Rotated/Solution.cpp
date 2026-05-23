// Problem Link : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/?envType=daily-question&envId=2026-05-23

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                c++;
            }
            if (c > 1)
                return false;
        }
        return true;
    }
};
