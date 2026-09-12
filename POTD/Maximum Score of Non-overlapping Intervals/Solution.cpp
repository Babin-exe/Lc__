// Problem Link : https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/description/
using ll = long long;
class Solution {
public:
    struct Node {
        ll score = -1;
        vector<int> ind;
    };

    vector<int> nextIdx;
    int n;

    vector<vector<Node>> dp;

    int finder(int s, vector<vector<int>>& intervals) {
        int l = 0, r = n - 1;
        int ans = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (intervals[mid][0] > s) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    Node solve(int idx, int k, vector<vector<int>>& intervals) {
        if (idx >= n || k <= 0)
            return Node();
        if (dp[idx][k].score != -1)
            return dp[idx][k];

        Node skip = solve(idx + 1, k, intervals);

        int sc = intervals[idx][2];
        int originalId = intervals[idx][3];

        Node right = solve(nextIdx[idx], k - 1, intervals);
        Node take = right;
        take.score += sc;
        take.ind.push_back(originalId);

        sort(begin(take.ind), end(take.ind));

        Node ans;
        if (skip.score > take.score) {
            ans = skip;

        } else if (take.score > skip.score) {
            ans = take;
        } else {

            if (skip.ind < take.ind) {
                ans = skip;
            } else
                ans = take;
        }

        return dp[idx][k] = ans;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();
        dp.assign(n, vector<Node>(5));
        nextIdx.resize(n);

        for (int i = 0; i < n; ++i) {
            intervals[i].push_back(i);
        }

        sort(begin(intervals), end(intervals));

        for (int i = 0; i < n; ++i) {
            nextIdx[i] = finder(intervals[i][1], intervals);
        }

        Node ans = solve(0, 4, intervals);
        return ans.ind;
    }
};
