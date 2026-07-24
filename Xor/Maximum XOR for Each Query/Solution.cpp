// Problem Link : https://leetcode.com/problems/maximum-xor-for-each-query/description/
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {

        int n = nums.size();
        vector<int> px(n);
        px[0] = nums[0];
        for (int i = 1; i < n; i++) {
            px[i] = px[i - 1] ^ nums[i];
        }

        int mask = (1 << maximumBit) - 1;

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int x = px[i];
            ans[n - 1 - i] = (x ^ mask);
        }
        return ans;
    }
};
