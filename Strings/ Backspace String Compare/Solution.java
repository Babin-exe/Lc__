// Problem link : https://leetcode.com/problems/backspace-string-compare/

class Solution {
    public boolean backspaceCompare(String s, String t) {
        Stack<Character> s1 = new Stack<>();
        Stack<Character> s2 = new Stack<>();
        int m = t.length();
        int n = s.length();
        
        for (int i = 0; i < m; i++) {
            char ch = t.charAt(i);
            if (ch != '#') {
                s1.push(ch);
            } else if (!s1.isEmpty()) {
                s1.pop();
            }
        }

        for (int j = 0; j < n; j++) {
            char ch = s.charAt(j);
            if (ch != '#') {
                s2.push(ch);
            } else if (!s2.isEmpty()) {
                s2.pop();
            }
        }

        return s1.equals(s2);
    }
}
