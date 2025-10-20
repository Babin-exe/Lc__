// Problem Link : https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/
class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int ans = 0;
        for (int i = 0; i < operations.length; i++) {
            String s = operations[i];
            if (s.charAt(0) == '+' || s.charAt(s.length() - 1) == '+')
                ans++;
            else
                ans--;
        }
        return ans;
    }
}
