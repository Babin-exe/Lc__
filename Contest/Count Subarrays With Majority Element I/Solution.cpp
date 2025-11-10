// Problem Link : https://leetcode.com/problems/count-subarrays-with-majority-element-i/description/

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int t_count = 0;
            for (int j = i; j < nums.size(); j++) {
                int idx = (j - i + 1) / 2;
                if (nums[j] == target) t_count++;
                if (t_count > idx) ans++;
            }
        }
        return ans;
    }
};
