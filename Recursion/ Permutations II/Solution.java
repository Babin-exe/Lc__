// Problem Link : https://leetcode.com/problems/permutations-ii/description/

class Solution {

    public List<Integer> temp = new ArrayList<>();
    public List<List<Integer>> result = new ArrayList<>();
    Map<Integer, Integer> mp = new HashMap<>();

    public void solve(int[] nums) {
        int n = nums.length;

        if (temp.size() == n) {
            result.add(new ArrayList<>(temp));
            return;
        }

        for (Map.Entry<Integer, Integer> mpp : mp.entrySet()) {

            if (mpp.getValue() == 0)
                continue;

            temp.add(mpp.getKey());
            mp.put(mpp.getKey(), mpp.getValue() - 1);
            solve(nums);
            temp.remove(temp.size() - 1);
            mp.put(mpp.getKey(), mpp.getValue() + 1);

        }

    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        for (int i = 0; i < nums.length; i++)
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        solve(nums);
        return result;
    }
}
