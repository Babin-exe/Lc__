//Problem Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
    char[][] digitToChars = {
            {}, // 0
            {}, // 1
            { 'a', 'b', 'c' }, // 2
            { 'd', 'e', 'f' }, // 3
            { 'g', 'h', 'i' }, // 4
            { 'j', 'k', 'l' }, // 5
            { 'm', 'n', 'o' }, // 6
            { 'p', 'q', 'r', 's' }, // 7
            { 't', 'u', 'v' }, // 8
            { 'w', 'x', 'y', 'z' } // 9
    };
    ArrayList<String> ans = new ArrayList<>();

    public void solve(String digits, int idx, StringBuilder make) {

        if (make.length() == digits.length()) {
            ans.add(make.toString());
            return;
        }
        if (idx == digits.length())
            return;

        int num = digits.charAt(idx) - '0';

        for (int j = 0; j < digitToChars[num].length; j++) {
            char ch = digitToChars[num][j];

            solve(digits, idx + 1, make.append(ch));
            make.deleteCharAt(make.length() - 1);
        }

    }

    public List<String> letterCombinations(String digits) {
        solve(digits, 0, new StringBuilder(""));
        return ans;
    }
}
