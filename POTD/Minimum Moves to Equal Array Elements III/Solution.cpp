// Problem Link : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/description/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(begin(nums), end(nums));
        int ans = 0;
        for (auto it : nums) {
            ans += maxi - it;
        }
        return ans;
    }
};
