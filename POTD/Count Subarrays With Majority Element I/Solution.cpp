// Problem Link : https://leetcode.com/problems/count-subarrays-with-majority-element-i

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int tc = 0;
            for (int j = i; j < n; j++) {
                int mj = (j - i + 1) / 2;
                if (nums[j] == target)
                    tc++;

                if (tc > mj)
                    ans++;
            }
        }

        return ans;
    }
};
