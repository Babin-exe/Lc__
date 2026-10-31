// Problem Link : https://leetcode.com/problems/maximize-sum-after-at-most-k-digit-rearrangements/

using ll = long long;
class Solution {
public:
    vector<ll> diff;

    ll giveMaxi(vector<int> nums) {
        ll maxi = 0;
        for (int i = 9; i >= 0; --i) {
            while (nums[i]) {
                maxi = maxi * 10 + i;
                nums[i]--;
            }
        }
        return maxi;
    }

    long long maximizeSum(vector<int>& nums, int k) {
        ll sum = accumulate(begin(nums), end(nums), 0LL);
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            vector<int> temp(10, 0);

            ll num = nums[i];
            while (num != 0) {
                ll val = num % 10;
                num /= 10;
                temp[val]++;
            }

            ll maxi = giveMaxi(temp);
            diff.push_back(maxi - nums[i]);
        }

        sort(rbegin(diff), rend(diff));
        for (int i = 0; i < k; ++i) {
            sum += diff[i];
        }

        return sum;
    }
};
