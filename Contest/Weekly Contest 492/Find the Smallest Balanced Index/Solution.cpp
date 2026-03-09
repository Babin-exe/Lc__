// Problem Link : https://leetcode.com/problems/find-the-smallest-balanced-index/description/

using ll = long long;
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {

        int n = nums.size();
        vector<ll> sum(n);
        vector<ll> prod(n);

        sum[0] = 0;
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        const ll LIMIT = 1e15; 
        prod[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {

            if (prod[i + 1] > LIMIT / nums[i + 1])
                prod[i] = LIMIT;
            else
                prod[i] = prod[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            if (sum[i] == prod[i])
                return i;
        }

        return -1;
    }
};
