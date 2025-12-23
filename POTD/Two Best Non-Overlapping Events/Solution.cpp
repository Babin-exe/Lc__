// Problem Link : https://leetcode.com/problems/two-best-non-overlapping-events/description/



class Solution {
public:
    int n;
    int dp[100001][3];

    int binarySearch(vector<vector<int>>& events, int endIdx) {
        int l = 0;
        int r = n - 1;
        int ans = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (events[mid][0] > endIdx) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int solve(vector<vector<int>>& events, int i, int count) {
        if (i >= n || count == 2)
            return 0;

        if (dp[i][count] != -1) {

            return dp[i][count];
        }

        int take = events[i][2] +
                   solve(events, binarySearch(events, events[i][1]), count + 1);
        int dontTake = solve(events, i + 1, count);

        return dp[i][count] = max(take, dontTake);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(begin(events), end(events));
        memset(dp, -1, sizeof(dp));
        return solve(events, 0, 0);
    }
};




