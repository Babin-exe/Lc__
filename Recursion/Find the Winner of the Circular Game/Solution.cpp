// Problem Link :https://leetcode.com/problems/find-the-winner-of-the-circular-game/
class Solution {
public:
    int Solve(int n, int k) {
        if (n == 1)
            return 0;
        return (Solve(n - 1, k) + k) % n;
    }
    int findTheWinner(int n, int k) { return Solve(n, k) + 1; }
};
