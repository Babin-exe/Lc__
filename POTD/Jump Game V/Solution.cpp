// Problem Link : https://leetcode.com/problems/jump-game-v/description/?envType=daily-question&envId=2026-05-24

class Solution {
public:
    int n;
    vector<int> dp;
    int explore(int i, vector<int>& arr, int d) {
        int ans = 1;

        if (dp[i] != -1)
            return dp[i];

        for (int left = i - 1; left >= max(0, i - d); left--) {
            if (arr[i] <= arr[left])
                break;

            int l = explore(left, arr, d);
            ans = max(ans, 1 + l);
        }

        for (int right = i + 1; right <= min(i + d, (int)arr.size() - 1);
             right++) {

            if (arr[i] <= arr[right])
                break;

            int r = explore(right, arr, d);
            ans = max(ans, 1 + r);
        }
        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        dp.resize(n, -1);
        int ans = -1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, explore(i, arr, d));
        }
        return ans;
    }
};
