// Problem Link : https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int a = INT_MAX;
        for(auto it : nums) a = min(a,it);

        for (auto it : nums) ans += it - a;
        return ans;
    }
};
