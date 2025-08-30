// Problem link : https://leetcode.com/problems/most-beautiful-item-for-each-query/description/

class Solution {
public:
    int findAns(int item, vector<vector<int>>& items) {
        int l = 0, r = items.size() - 1;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (items[mid][0] > item) {
                r = mid - 1;
            } else if (items[mid][0] <= item) {
                ans = items[mid][1];
                l = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {

        sort(begin(items), end(items),
             [](auto& a, auto& b) { return a[0] < b[0]; }

        );
        int n = queries.size();
        for (int i = 1; i < items.size(); i++) {
            items[i][1] = max(items[i - 1][1], items[i][1]);
        }
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            ans[i] = findAns(queries[i], items);
        }
        return ans;
    }
};
