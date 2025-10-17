// Problem Link : https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations

class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int a : nums) {
            int val = ((a % value) + value) % value;
            mp.put(val, mp.getOrDefault(val, 0) + 1);
        }

        int hehe = 0;
        while (mp.getOrDefault(hehe % value, 0) > 0) {
            mp.put(hehe % value, mp.getOrDefault(hehe % value, 0) - 1);
            hehe++;
        }
        return hehe;
    }
}
