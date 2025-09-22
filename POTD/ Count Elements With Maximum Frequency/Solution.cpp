// Problem link : https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2025-09-22
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int ans = 0;
        int var = 0;
        for (auto& take : mp) {
            int val = take.second;
            if (val == var) {
                ans += val;

            } else if (val > var) {
                ans = val;
                var = val;
            }
        }
        return ans;
    }
};
