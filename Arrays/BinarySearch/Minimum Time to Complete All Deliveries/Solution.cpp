// Problem Link : https://leetcode.com/problems/minimum-time-to-complete-all-deliveries/

class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {

        long L = 0, R = 1e15, ans = 1e15;
        while (L <= R) {
            long mid = (L + R) / 2;
            long d0 = mid - mid / r[0];
            long d1 = mid - mid / r[1];
            long d_01 = mid - (mid / lcm(r[0], r[1]));

            if (d[0] + d[1] <= d_01 && d[0] <= d0 && d[1] <= d1) {
                ans = min(ans, mid);
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }

        return ans;
    }
};
