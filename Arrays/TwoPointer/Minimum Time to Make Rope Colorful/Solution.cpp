// Problem Link : https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0, j = 0;
        int maxi = 0;
        int sum = 0;
        int n = neededTime.size();
        while (i < n && j < n) {
            if (colors[i] == colors[j]) {
                sum += neededTime[j];
                maxi = max(maxi, neededTime[j]);
                j++;
            } else {
                sum -= maxi;
                maxi = 0;
                i = j;
            }
        }
        sum -= maxi;
        return sum;
    }
};
