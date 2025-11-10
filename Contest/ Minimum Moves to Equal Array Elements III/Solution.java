// Problem Link : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/description/

class Solution {
    public int minMoves(int[] nums) {
        int maxi = -1;
        int ans = 0;
        for (int take : nums) {
            if (take > maxi)
                maxi = take;
        }
        for(int t:nums){
            ans +=Math.abs(maxi-t );
        }
        return ans;
    }
}
