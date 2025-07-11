// Problem link : https://leetcode.com/problems/contains-duplicate-ii/description/



class Solution {


    public boolean containsNearbyDuplicate(int[] nums, int k) {
       
        Set<Integer> set = new HashSet<>();
        int i = 0, j = 0;
        int n = nums.length;
        while (j < n) {
            if (j - i > k) {
                set.remove(nums[i]);
                i++;
            }
            if (set.contains(nums[j])) {
                return true;
            }

            set.add(nums[j]);
            j++;

        }
        return false;
    }
}
