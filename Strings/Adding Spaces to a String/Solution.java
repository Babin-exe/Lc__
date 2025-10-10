// Problem Link : https://leetcode.com/problems/adding-spaces-to-a-string/description/
class Solution {
    public String addSpaces(String s, int[] spaces) {
        // StringBuilder hehe = new StringBuilder(s);
        // int n = spaces.length;
        // int increased = 0;
        // for (int i = 0; i < n; i++) {
        //     int index = spaces[i];
        //     hehe.insert(index + increased, " ");
        //     increased++;

        // }
        // return hehe.toString();

        StringBuilder hehe = new StringBuilder();
        int n = spaces.length;
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (j < n && i == spaces[j]) {
                hehe.append(' ');
                j++;
            }
            hehe.append(s.charAt(i));

        }

        return hehe.toString();
    }
}
