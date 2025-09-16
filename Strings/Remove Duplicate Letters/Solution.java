// Problem link : https://leetcode.com/problems/remove-duplicate-letters/

class Solution {
    public String removeDuplicateLetters(String s) {
        StringBuilder hehe = new StringBuilder();
        int[] index = new int[26];
        boolean[] prev = new boolean[26];

        for (int i = 0; i < s.length(); i++) {
            index[s.charAt(i) - 'a'] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            if (prev[s.charAt(i) - 'a'])
                continue;
            char ch = s.charAt(i);

            while (hehe.length() > 0 && ch < hehe.charAt(hehe.length() - 1)
                    && index[hehe.charAt(hehe.length() - 1) - 'a'] > i) {
                        
                prev[hehe.charAt(hehe.length() - 1) - 'a'] = false;
                hehe.deleteCharAt(hehe.length() - 1);

            }

            hehe.append(ch);
            prev[ch - 'a'] = true;

        }
        return hehe.toString();

    }
}
