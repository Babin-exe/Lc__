// Problem Link : https://leetcode.com/problems/different-ways-to-add-parentheses/


class Solution {

    public List<Integer> solve(String e) {
        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i < e.length(); i++) {

            if (e.charAt(i) == '-' || e.charAt(i) == '+' || e.charAt(i) == '*') {

                List<Integer> left = new ArrayList<>();
                left = solve(e.substring(0, i));

                List<Integer> right = new ArrayList<>();
                right = solve(e.substring(i + 1));

                for (int a : left) {
                    for (int b : right) {
                        if (e.charAt(i) == '-') {
                            ans.add(a - b);
                        } else if (e.charAt(i) == '+') {
                            ans.add(a + b);
                        }
                        if (e.charAt(i) == '*') {
                            ans.add(a * b);
                        }
                    }
                }

            }

        }

        if (ans.size() == 0) {
            int number = Integer.parseInt(e);
            ans.add(number);
        }

        return ans;
    }

    public List<Integer> diffWaysToCompute(String e) {
        return solve(e);

    }
}
