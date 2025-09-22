// Problem link : https://leetcode.com/problems/unique-length-3-palindromic-subsequences/submissions/1779409690/
class Solution {

    public int countPalindromicSubsequence(String s) {

        int[] first = new int[26];
        int[] last = new int[26];
        Arrays.fill(first, -1);
        Arrays.fill(last, -1);

        int n = s.length();
        for (int i = 0; i < n; i++) {
            int ch = s.charAt(i) - 'a';
            if (first[ch] == -1)
                first[ch] = i;
            last[ch] = i;

        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            HashSet<Character> hs = new HashSet<>();
            for (int a = first[i] + 1; a < last[i]; a++) {
                if (!hs.contains(s.charAt(a))) {
                    ans++;
                    hs.add(s.charAt(a));
                }
            }
        }

        return ans;
    }
}
