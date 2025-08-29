// Problem link : https://leetcode.com/problems/magnetic-force-between-two-balls/description/

class Solution {

public:
    bool isPossible(vector<int>& position, int target, int m) {
        int cur = position[0];
        int val = 1;
        for (int i = 1; i < position.size(); i++) {
            int auh = position[i];
            if (auh - cur >= target) {
                val++;
                cur = auh;
            }
            if (val == m)
                break;
        }
        return val == m;
    }

public:
    int maxDistance(vector<int>& position, int m) {
        sort(begin(position), end(position));
        int n = position.size();
        int l = 1, r = position[n - 1] - position[0];
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(position, mid, m)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
