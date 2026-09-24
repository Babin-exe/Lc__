// Problem Link : https://leetcode.com/problems/maximum-pulse-value-after-one-subarray-rotation/
using ll = long long;
class Solution {
public:
    long long maxValue(vector<int>& nums) {

        int n = nums.size();

        int p_sum = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2)
                p_sum -= nums[i];
            else
                p_sum += nums[i];
        }

        ll max_sum = 0;
        ll even_stuff = 0;
        ll odd_stuff = INT_MIN;

        for (int i = 0; i < n; ++i) {
            
            ll cur = (i % 2 ? nums[i] : -nums[i]);
            ll new_even = odd_stuff + cur;
            ll new_odd = max(cur, even_stuff + cur);

            even_stuff = new_even;
            odd_stuff = new_odd;

            max_sum = max(max_sum, even_stuff);
        }

        return p_sum + 2 * max_sum;
    }
};
