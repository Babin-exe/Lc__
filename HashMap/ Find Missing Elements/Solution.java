// Problem Link : https://leetcode.com/problems/find-missing-elements/

class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        Set<Integer> set = new HashSet<>();

        Arrays.sort(nums);

        for (int num : nums) {
            set.add(num);
        }

        for (int i = nums[0]; i <= nums[nums.length - 1]; i++) {
            if (!set.contains(i)) {
                ans.add(i);
            }
        }

        return ans;
    }
}
