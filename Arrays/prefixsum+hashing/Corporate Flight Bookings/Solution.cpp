// Problem Link : https://leetcode.com/problems/corporate-flight-bookings/description/
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& b, int n) {
        vector<int> ps(n + 2);
        for (int i = 0; i < b.size(); i++) {
            int l = b[i][0];
            int r = b[i][1];
            int c = b[i][2];

            ps[l] += c;
            ps[r + 1] -= c;
        }
        vector<int> ans(n);
        ans[0] = ps[1];
        int sum = ans[0];

        for (int i = 2; i <= n; i++) {
            ans[i - 1] = sum + ps[i];
            sum = ans[i - 1];
        }

        return ans;
    }
};
