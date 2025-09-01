// Problem link : https://leetcode.com/problems/count-and-say/

class Solution {
    public String countAndSay(int n) {
        if (n == 1)
            return "1";

        String hehe = countAndSay(n - 1);
        StringBuilder ans = new StringBuilder("");

        for (int i = 0; i < hehe.length(); i++) {
            int count = 1;
            char ch = hehe.charAt(i);
            while (i < hehe.length() - 1 && hehe.charAt(i) == hehe.charAt(i + 1)) {
                count++;
                i++;
            }

            ans.append(count).append(ch);

        }

        return ans.toString();
    }
}
