// Problem Link : https://leetcode.com/problems/number-of-intersecting-interval-pairs-i/description/
class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& in) {
        sort(begin(in), end(in));
        int count = 0;
        int n = in.size();
        for (int i = 0; i < n; i++) {
            int l = in[i][0];
            int r = in[i][1];
            for (int j = i + 1; j < n; ++j) {
                int ol = in[j][0];
                int orr = in[j][1];

                if (r >= ol) {
                    count++;
                }
            }
        }
        return count;
    }
};
