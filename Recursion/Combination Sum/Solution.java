// Problem Link : https://leetcode.com/problems/combination-sum/

class Solution {
    List<Integer> temp = new ArrayList<>();
    List<List<Integer>> result = new ArrayList<>();
    int sum = 0;

    public void solve(int i, int[] candidates, int target) {
        if (sum == target) {
            result.add(new ArrayList<>(temp));
            return;
        }

        if (i == candidates.length || sum > target)
            return;

        for (int j = i; j < candidates.length; j++) {

            if (sum + candidates[j] > target)
                continue;

            sum += candidates[j];
            temp.add(candidates[j]);
            solve(j, candidates, target);
            sum -= candidates[j];
            temp.remove(temp.size() - 1);

        }

    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        solve(0, candidates, target);
        return result;
    }
}
