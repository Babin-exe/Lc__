// Problem Link : https://leetcode.com/problems/separate-black-and-white-balls/description/
class Solution {
    public long minimumSteps(String s) {
        int n = s.length();
        long ans = 0;
        long one_count = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '0') {
                ans += one_count;

            } else {
                one_count++;
            }

        }
        return ans;
    }
}
