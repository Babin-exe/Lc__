// Problem link : https://leetcode.com/problems/delete-columns-to-make-sorted/
class Solution {
    public int minDeletionSize(String[] strs) {
        int m = strs.length;
        int n = strs[0].length();
        int count = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m - 1; i++) {
                if (strs[i].charAt(j) > strs[i+1].charAt(j)) {
                    count++;
                    break;
                }
            }
        }

        return count;
    }
}
