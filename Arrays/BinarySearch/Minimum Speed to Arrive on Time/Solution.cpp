// Problem link : https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
class Solution {

public:
    bool hehe(vector<int>& dist, double hour, int mid) {
        double ans = 0;
        for (int i = 0; i < dist.size() - 1; i++) {
            ans += ceil(dist[i] / (double)mid);
        }
        ans += (dist[dist.size() - 1] / (double)mid);
        return ans <= hour;
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = (int)1e7;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (hehe(dist, hour, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
