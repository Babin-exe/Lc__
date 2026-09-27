// Problem Link : https://leetcode.com/problems/longest-subarray-divisible-by-k-with-at-most-one-negation-i/description/
using ll = long long;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        auto mod = [&](ll x) { return (x % k + k) % k; };

        vector<pair<int, int>> m;
        for (int i = 0; i < n; ++i) {
            ll val = mod(2LL * nums[i]);
            m.push_back({val, i});
        }
        sort(begin(m), end(m));

        vector<int> ps(n, 0);
        ps[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            ps[i] = ps[i - 1] + nums[i];
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; j++) {
                int sub = ps[j];

                if (i - 1 >= 0) {
                    sub -= ps[i - 1];
                }

                if (sub % k == 0) {
                    ans = max(ans, j - i + 1);
                    continue;
                }

                ll hehe = mod(sub);

                auto it = lower_bound(begin(m), end(m), make_pair(hehe, i));

                if (it != m.end() && it->first == mod(hehe) &&
                    it->second <= j) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
