// Problem Link : https://leetcode.com/problems/maximum-subarray-sum-after-multiplier/
using ll = long long;
class Solution {
public:
    ll solve(vector<int>& nums, vector<ll>& ch) {
        ll p1 = nums[0], p2 = ch[0], p3 = LLONG_MIN;

        ll ans = max(1LL * nums[0], ch[0]);

        for (int i = 1; i < n; i++) {
            ll p11 = max(1LL * nums[i], p1 + nums[i]);
            ll p22 = max({ch[i], ch[i] + p1, ch[i] + p2});
            ll p33 = max(1LL * nums[i] + p2,
                         (p33 == LLONG_MIN ? LLONG_MIN : nums[i] + p3));

            ans = max({ans, p11, p22, p33});
            p1 = p11;
            p2 = p22;
            p3 = p33;
        }

        return ans;
    }
    int n;
    long long maxSubarraySum(vector<int>& nums, int k) {
        n = nums.size();
        vector<ll> mul(n), div(n);
        for (int i = 0; i < n; i++) {
            ll m = 1LL * nums[i] * k;
            ll d = nums[i] >= 0 ? nums[i] / k : ceil(nums[i] / k);
            mul[i] = m;
            div[i] = d;
        }

        return max(solve(nums, mul), solve(nums, div));
    }
};
