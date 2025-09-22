// Problem link : https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2025-09-22
class Solution {
    public int maxFrequencyElements(int[] nums) {
        int n = nums.length;
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int a : nums) {
            mp.put(a, mp.getOrDefault(a, 0) + 1);
        }
        int ans = 0;
        int maxi = 0;
        for (Map.Entry<Integer, Integer> m : mp.entrySet()) {
            int val = m.getValue();
            if (val == maxi) {
                ans += val;
            } else if (val > maxi) {
                maxi = val;
                ans = val;
            }
        }
        return ans;

    }
}
