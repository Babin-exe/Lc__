// Problem Link : https://leetcode.com/problems/maximum-product-of-three-elements-after-one-replacement/description/


class Solution {
    public long maxProduct(int[] nums) {
        long lar = Long.MIN_VALUE;
        long slar = Long.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            if (Math.abs(nums[i]) > lar) {
                slar = lar;
                lar = Math.abs(nums[i]);
            } else if (slar < Math.abs(nums[i])) {
                slar = Math.abs(nums[i]);
            }
        }
        return lar * slar * (100000L);
    }
}
