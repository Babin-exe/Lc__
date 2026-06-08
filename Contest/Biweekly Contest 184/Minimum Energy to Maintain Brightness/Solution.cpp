// Problem Link : https://leetcode.com/problems/minimum-energy-to-maintain-brightness/description/

class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int m = intervals.size();
        sort(begin(intervals), end(intervals));
        int s = intervals[0][0];
        int e = intervals[0][1];

        long long interval = 0;
        int cost = ceil(brightness / 3.0);
        for (int i = 1; i < m; i++) {
            int ns = intervals[i][0];
            int ne = intervals[i][1];
            if (ns <= e) {
                e = max(e, ne);
            } else {
                interval += (e - s) + 1;
                s = ns;
                e = ne;
            }
        }

        interval += (e - s + 1);

        return interval * cost;
    }
};
