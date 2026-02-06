import java.util.*;

class Solution {
    List<String> ans = new ArrayList<>();
    StringBuilder temp = new StringBuilder();

    void solve(int i, String s) {
        if (i == s.length()) {
            ans.add(temp.toString());
            return;
        }

        char ch = s.charAt(i);

        if (Character.isDigit(ch)) {
            temp.append(ch);
            solve(i + 1, s);
            temp.deleteCharAt(temp.length() - 1);
        } else {

            temp.append(Character.toUpperCase(ch));
            solve(i + 1, s);
            temp.deleteCharAt(temp.length() - 1);


            temp.append(Character.toLowerCase(ch));
            solve(i + 1, s);
            temp.deleteCharAt(temp.length() - 1);
        }
    }

    public List<String> letterCasePermutation(String s) {
        solve(0, s);
        return ans;
    }
}
