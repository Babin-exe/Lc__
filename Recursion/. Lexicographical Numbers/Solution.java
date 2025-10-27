// Problem Link : https://leetcode.com/problems/lexicographical-numbers/

 class Solution {
    List<Integer> ans = new ArrayList<>();

    public void solve(int num, int n) {
        if (num > n)
            return;

        ans.add(num);
        for (int i = 0; i <= 9; i++) {
            int hehe = (num * 10) + i;
            if (hehe > n)
                return;

            solve(hehe, n);
        }
    }

    public List<Integer> lexicalOrder(int n) {
        for (int i = 1; i <= 9; i++) {
            solve(i, n);
        }
        return ans;
    }
}
