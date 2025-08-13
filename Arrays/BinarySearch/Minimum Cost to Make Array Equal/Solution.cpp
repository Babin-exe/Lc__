// Problem link : https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/

class Solution {
    typedef long long ll;

public:
    long long minCost(vector<int>& nums, vector<int>& cost, int c) {
        ll ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += (long)abs(nums[i] - c) * cost[i];
        }
        return ans;
    }

public:
    long long minCost(vector<int>& nums, vector<int>& cost) {

        int left = *min_element(begin(nums), end(nums));
        int right = *max_element(begin(nums), end(nums));

        ll ans = INT_MAX;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            ll cost_1 = minCost(nums, cost, mid);
            ll cost_2 = minCost(nums, cost, mid + 1);

            ans = min(cost_1, cost_2);
            if (cost_2 > cost_1) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
