// Problem Link : https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements/
using ll = long long;
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {

        int n = nums.size() - 1;
        sort(rbegin(nums), rend(nums));
        ll sum = 0;
        int g = min(mul - 1, k);
        k -= g;
        int i = 0;
        while (g--) {
            sum = sum + (1LL * nums[i] * mul);
            i++;
            mul--;
        }

        while (k > 0) {
            sum += nums[i];
            i++;
            k--;
        }

        return sum;
    }
};
