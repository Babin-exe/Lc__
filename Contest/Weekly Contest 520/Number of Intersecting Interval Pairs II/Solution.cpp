// Problem Link : https://leetcode.com/problems/number-of-intersecting-interval-pairs-ii/
class Solution {
public:
    int n;
    int bs(int start, vector<vector<int>>& it) {
        int end = n - 1;
        int sr = it[start][1];
        int ans =  - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (it[mid][0] <= sr) {
                ans = mid;
                start = mid + 1;
            } else
                end = mid - 1;
        }
        return ans;
    }
    long long countIntersectingIntervals(vector<vector<int>>& it) {
        n = it.size();
        sort(begin(it), end(it));
        long long count = 0;
        for (int i = 0; i < n; ++i) {
            int b = bs(i, it);
            if (b != -1)
                count += (b - i);
        }
        return count;
    }
};
