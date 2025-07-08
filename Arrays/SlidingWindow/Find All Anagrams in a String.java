// Problem No : 438
// Problem Link : https://leetcode.com/problems/find-all-anagrams-in-a-string/description/


 class Solution {

    private static boolean check(int[] hehe) {
        for (int a : hehe) {
            if (a != 0) {
                return false;
            }
        }
        return true;
    }

    public List<Integer> findAnagrams(String s, String p) {

        List<Integer> freq = new ArrayList<>();
        int[] take = new int[26];
        //populate the frequency array
        for (char ch : p.toCharArray()) {
            take[ch - 'a']++;
        }

        int i = 0, j = 0;
        int n = s.length();
        while (j < n) {

            take[s.charAt(j) - 'a']--;
            if (j - i + 1 == p.length()) {
                if (check(take)) {
                    freq.add(i);
                }
                take[s.charAt(i) - 'a']++;
                i++;
            }
            j++;

        }
        return freq;
    }
}
