// Problem Link : https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

class Solution {

    public int Hehe(int n, int k) {
        if (n == 1)
            return 0;

        return (Hehe(n - 1, k) + k) % n;

    }

    public int findTheWinner(int n, int k) {

        int ans = Hehe(n, k);
        return ans + 1;
        
        // List<Integer> arr = new ArrayList<>();
        // for (int i = 1; i <= n; i++) {
        //     arr.add(i);
        // }

        // int i = 0;
        // while (arr.size() > 1) {
        //     int s = arr.size();
        //     int idx = (i + k - 1) % s;
        //     arr.remove(idx);
        //     i = idx;
        // }
        // int val = arr.get(0);
        // return val;
        ///////////////////////////////////////////////////////////////////////////////////////
        // Queue<Integer> q = new ArrayDeque<>();
        // for (int i = 1; i <= n; i++) {
        //     q.offer(i);
        // }

        // while (q.size() > 1) {

        //     for (int i = 1; i <= k - 1; i++) {
        //         q.offer(q.poll());
        //     }
        //     q.poll();
        // }
        // return q.peek();
        /////////////////////////////////////////////////////////////////////////////////////////

    }
}
