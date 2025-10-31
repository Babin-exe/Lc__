// Problem Link : https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/
class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        int val = 0;
        int[] hehe = new int[2];
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }

        for (Map.Entry<Integer, Integer> m : mp.entrySet()) {
            int take = m.getValue();
            int numm = m.getKey();
            if (take == 2) {
                hehe[val] = numm;
                val++;
            }
        }
        return hehe;
    }
}
