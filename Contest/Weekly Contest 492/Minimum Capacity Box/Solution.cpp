// Problem Link : https://leetcode.com/problems/minimum-capacity-box/description/

class Solution {
public:
    int minimumIndex(vector<int>& c, int it) {
        int n = c.size();
        int ans = INT_MAX;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (c[i] >= it && ans > c[i]) {
                ans = c[i];
                idx = i;
            }
        }
        return idx;
    }
};
