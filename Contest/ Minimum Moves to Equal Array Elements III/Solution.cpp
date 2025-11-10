// Problem Link : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/description/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = -1, ans = 0;
        for (int a : nums) {
            if (maxi < a)
                maxi = a;
        }
        for (int b : nums) {
            ans += abs(b - maxi);
        }
        return ans;
    }
};
