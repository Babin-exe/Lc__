// Problem Link : https://leetcode.com/problems/jump-game-vii/description/?envType=daily-question&envId=2026-05-25

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        int n = s.length();
        if (s[n - 1] != '0') return false;

        vector<bool> seen(n, false);
        queue<int> q;
        q.push(0);
        seen[0] = true;

        int left_far = 0;

        while (!q.empty()) {

            int front = q.front();
            q.pop();

            if (front == n - 1)
                return true;

            int low = max(front + minJump, left_far + 1);
            int high = min(n - 1, front + maxJump);

            for (int i = low; i <= high; i++) {
                if (seen[i] == false) {
                    seen[i] = true;
                    if (s[i] == '0')
                        q.push(i);
                }
            }
            left_far = high;
        }
        return false;
    }
};
