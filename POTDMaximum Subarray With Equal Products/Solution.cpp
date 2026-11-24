// Problem Link : https://leetcode.com/problems/maximum-subarray-with-equal-products/
using ll = long long;
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        const ll LIMIT = 2520LL * 10; 

        for (int i = 0; i < n; ++i) {
            ll prod = 1;
            ll g = nums[i];
            ll l = nums[i];

            for (int j = i; j < n; ++j) {
                prod *= nums[j];
                if (prod > LIMIT) break; 

                g = gcd(g, (ll)nums[j]);
                l = lcm(l, (ll)nums[j]);

                if (g * l == prod) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
