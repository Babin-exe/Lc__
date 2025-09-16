// Problem link : https://leetcode.com/problems/is-subsequence/description/

class Solution {
    public boolean isSubsequence(String s, String t) {
        int n = t.length();
        int a = s.length();
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (idx == a)
                break;
            if (t.charAt(i) == (s.charAt(idx))) {
                idx++;
            }
        }
        return idx == a;
    }
}
