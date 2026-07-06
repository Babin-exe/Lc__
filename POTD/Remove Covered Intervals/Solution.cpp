// Problem Link : https://leetcode.com/problems/divisible-game/
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();
        int ans = 0;

        sort(begin(intervals),end(intervals));

        for (int i = 0; i < n; i++) {

            int ml = intervals[i][0];
            int mr = intervals[i][1];

            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;

                int Ol = intervals[j][0];
                int Or = intervals[j][1];

                if (ml < Ol) {
                    break;
                }

                if (mr <= Or) {
                    ans++;
                    break;
                }
            }
        }

        return n - ans;
    }
};

 
