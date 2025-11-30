// Problem Link : https://leetcode.com/problems/subsets-ii/

class Solution {
    List<Integer> temp = new ArrayList<>();
    List<List<Integer>> result = new ArrayList<>();

    public void solve(int i, int[] nums) {
        if (i == nums.length) {
            result.add(new ArrayList<>(temp));
            return;
        }

        temp.add(nums[i]);
        solve(i + 1, nums);
        temp.remove(temp.size() - 1);
        while (i + 1 < nums.length && nums[i] == nums[i + 1])
            i++;
        solve(i + 1, nums);
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        solve(0, nums);
        return result;
    }
}
