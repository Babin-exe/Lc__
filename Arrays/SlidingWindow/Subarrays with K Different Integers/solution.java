// Problem link : https://leetcode.com/problems/subarrays-with-k-different-integers/description/
// Time complexity : O(n)
// Space complexity : O(n)


class Solution {

    private int slidingWindow(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();

        int count = 0, n = nums.length, i = 0, j = 0;

        while (j < n) {

            int take = nums[j];
            map.put(take, map.getOrDefault(take, 0) + 1);
            while (map.size() > k) {
                int taker = nums[i];
                map.put(taker, map.getOrDefault(taker, 0) - 1);

                if (map.get(taker) == 0) {
                    map.remove(taker);
                }
                i++;

            }
            count = count + (j - i + 1);
            j++;
        }

        return count;
    }

    public int subarraysWithKDistinct(int[] nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);

    }
}
