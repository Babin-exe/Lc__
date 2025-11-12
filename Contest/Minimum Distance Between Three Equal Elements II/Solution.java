// Problem Link : https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/description/

class Solution {
    public int minimumDistance(int[] nums) {
        int ans = Integer.MAX_VALUE;
        HashMap<Integer, List<Integer>> mp = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            mp.putIfAbsent(nums[i], new ArrayList<>());
            mp.get(nums[i]).add(i);

        }

        for (Map.Entry<Integer, List<Integer>> val : mp.entrySet()) {
            List<Integer> take = val.getValue();
            int vall = Integer.MAX_VALUE;
            if (take.size() < 3)
                continue;
            for (int i = 0; i < take.size() - 2; i++) {
                vall = Math.min(vall, 2 * (take.get(i + 2) - take.get(i)));
            }

            ans = Math.min(ans, vall);

        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
