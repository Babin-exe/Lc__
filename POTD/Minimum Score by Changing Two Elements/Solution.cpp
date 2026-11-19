// Problem Link : https://leetcode.com/problems/minimum-score-by-changing-two-elements/description
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();

    

        int first = nums[n - 1] - nums[2];
        int second = nums[n - 3] - nums[0];
        int third = nums[n - 2] - nums[1];

        return min({first, second, third});
    }
};
