// Problem Link : https://leetcode.com/problems/count-special-triplets/

import java.util.HashMap;
import java.util.List;

class Solution {

    public int specialTriplets(int[] nums) {

        long count = 0;
        final int MOD = 1_000_000_007;

        HashMap<Integer, Integer> leftCount = new HashMap<>();
        HashMap<Integer, Integer> rightCount = new HashMap<>();

        int n = nums.length;

        for (int take : nums) {
            rightCount.put(take, rightCount.getOrDefault(take, 0) + 1);
        }

        for (int i = 0; i < n; i++) {
            int currentElement = nums[i];

            rightCount.put(currentElement, rightCount.get(currentElement) - 1);

            int requiredVal = currentElement * 2;

            if (leftCount.getOrDefault(requiredVal, 0) >= 1 &&
                    rightCount.getOrDefault(requiredVal, 0) >= 1) {

                long le = leftCount.get(requiredVal);
                long re = rightCount.get(requiredVal);

                long prod = (le * re) % MOD;

                count = (count + prod) % MOD;
            }

            leftCount.put(currentElement, 
            leftCount.getOrDefault(currentElement, 0) + 1);
        }

        return (int) count;
    }
}
