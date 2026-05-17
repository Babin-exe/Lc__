// Problem Link : https://leetcode.com/problems/jump-game-iii/description/?envType=daily-question&envId=2026-05-17

class Solution {
public:
    bool solve(vector<int>& arr, int i) {
        if (i < 0 || i >= arr.size() || arr[i] < 0)
            return false;

        if (arr[i] == 0) return true;

        arr[i] *= -1;

        int l = solve(arr, i - arr[i]);
        int r = solve(arr, i + arr[i]);
        return l || r;
    }
    bool canReach(vector<int>& arr, int start) { return solve(arr, start); }
};
