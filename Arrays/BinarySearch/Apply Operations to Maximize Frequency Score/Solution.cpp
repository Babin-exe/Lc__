// Problem link : https://leetcode.com/problems/apply-operations-to-maximize-frequency-score/description/
class Solution {
    typedef long long ll;

public:
    bool isPossible(int len, vector<int>& nums, vector<ll>& prefix, ll k,
                    int n) {

        int i = 0, j = len - 1;

        while (j < n) {

            int target_idx = i + (j - i) / 2;
            int target = nums[target_idx];

            ll left_sum = (target_idx > 0 ? prefix[target_idx - 1] : 0) -
                          ((i > 0) ? prefix[i - 1] : 0);
            ll right_sum = prefix[j] - prefix[target_idx];

            ll left_opr = (long)(target_idx - i) * target - left_sum;
            ll right_opr = right_sum - (long)(j - target_idx) * target;

            if (left_opr + right_opr <= k) {
                return true;
            }
            i++;
            j++;
        }

        return false;
    }

public:
    int maxFrequencyScore(vector<int>& nums, long long k) {

        int n = nums.size();
        int l = 1, r = n;
        sort(begin(nums), end(nums));
        int ans = 1;

        vector<ll> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(mid, nums, prefix, k, n)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
