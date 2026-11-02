// Problem Link : https://leetcode.com/problems/minimum-value-of-merged-integers/description/
class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n - 1; i += 2) {
            string s1 = to_string(nums[i]);
            string s2 = to_string(nums[i + 1]);

            string s3 = s1 + s2;

            int num = stoi(s3);

            ans = min(ans, num);
        }
        return ans;
    }
};
