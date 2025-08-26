// Problem link : https://leetcode.com/problems/most-profit-assigning-work/description/

class Solution {

public:
    int binarySearch(vector<pair<int, int>>& stuff, int target) {
        int ans = -1;
        int l = 0, r = stuff.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target >= stuff[mid].first) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> stuff(n);

        for (int i = 0; i < n; i++) {
            stuff[i].first = difficulty[i];
            stuff[i].second = profit[i];
        }

        sort(begin(stuff), end(stuff));
        for (int i = 1; i < n; i++) {

            stuff[i].second = max(stuff[i - 1].second, stuff[i].second);
        }

        int ans = 0;
        int m = worker.size();
        for (int i = 0; i < m; i++) {
            int id = binarySearch(stuff, worker[i]);
            if (id != -1) {
                ans += stuff[id].second;
            }
        }
        return ans;
    }
};
