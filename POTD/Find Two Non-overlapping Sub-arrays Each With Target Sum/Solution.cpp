// Probelm Link : https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/
using ll = long long;
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0, j = 0;
        ll sum = 0;
        ll flow = LLONG_MAX;
        ll ans = LLONG_MAX;
        vector<ll> prev(n, LLONG_MAX);

        while (i < n && j < n) {
            sum += arr[j];
            while (i < j && sum > target)
                sum -= arr[i++];

            if (sum == target) {
                ll len = j - i + 1;

                if (i > 0 && prev[i - 1] != LLONG_MAX) {
                    ans = min(ans, len + prev[i - 1]);
                }

                flow = min(flow, len);
            }

            prev[j] = flow;
            j++;
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};
