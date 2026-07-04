// Problem Link : https://leetcode.com/problems/unique-middle-element/
class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;
        int val = nums[mid];
        for (int i = 0; i < n; i++) {
            if (i != mid) {
                if (nums[i] == val)
                    return false;
            }
        }
        return true;
    }
};
