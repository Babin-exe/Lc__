// Problem Link : https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int sec = 0;
        for (int i = 0; i < nums.size(); i++) {
            sec += nums[i];
            if (sec > sum) {
                sum = sec;
            }

            if (sec < 0) {
                sec = 0;
            }

        }
        return sum;
    }
};
