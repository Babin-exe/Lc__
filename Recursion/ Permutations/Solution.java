// Problem Link : https://leetcode.com/problems/permutations/description/

class Solution {
    Set<Integer> st = new HashSet<>();
    List<List<Integer>> result = new ArrayList<>();
    List<Integer> temp = new ArrayList<>();

    public void solve(List<List<Integer>> result, List<Integer> temp, int[] nums) {
        if (temp.size() == nums.length) {
            result.add(new ArrayList<>(temp));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (!st.contains(nums[i])) {
                temp.add(nums[i]);
                st.add(nums[i]);
                solve(result, temp, nums);
                temp.remove(temp.size() - 1);
                st.remove(nums[i]);
            }
        }

    }

    public List<List<Integer>> permute(int[] nums) {
        solve(result, temp, nums);
        return result;
    }
}
