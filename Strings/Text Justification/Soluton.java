// Problem link : https://leetcode.com/problems/text-justification/
class Solution {

    public String findLine(int i, int j, int each_hole, int extra_hole, int maxWidth, String[] words) {
        StringBuilder hehe = new StringBuilder("");
        for (int k = i; k < j; k++) {
            hehe.append(words[k]);
            if (k == j - 1)
                continue;

            for (int l = 1; l <= each_hole; l++) {
                hehe.append(" ");
            }
            if (extra_hole > 0) {
                hehe.append(" ");
                extra_hole--;
            }
        }

        while (hehe.length() < maxWidth) {
            hehe.append(" ");
        }

        return hehe.toString();
    }

    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> ans = new ArrayList<>();
        int n = words.length;
        int i = 0;
        while (i < n) {

            int word_length = words[i].length();
            int j = i + 1;
            int hole = 0;
            while (j < n && word_length + words[j].length() + 1 + hole <= maxWidth) {
                word_length += words[j].length();
                hole++;
                j++;
            }
            int rem_space = maxWidth - word_length;
            int each_hole = hole == 0 ? 0 : rem_space / hole;
            int extra_hole = hole == 0 ? 0 : rem_space % hole;
            if (j == n) {
                each_hole = 1;
                extra_hole = 0;
            }
            ans.add(findLine(i, j, each_hole, extra_hole, maxWidth, words));
            i = j;

        }
        return ans;
    }
}
