// Problem Link : https://leetcode.com/problems/sum-of-integers-with-maximum-digit-range/
using ll = long long;
class Solution {
public:
    pair<int, int> gmm(int a) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        while (a != 0) {
            int m = a % 10;
            a /= 10;
            maxi = max(maxi, m);
            mini = min(mini, m);
        }

        return {mini, maxi};
    }
    int maxDigitRange(vector<int>& nums) {

        map<int, vector<int>> mp;
        int n = nums.size();
        int hi = -1;

        for (int i = 0; i < n; i++) {
            auto [mi, mx] = gmm(nums[i]);

            hi = max(hi, mx - mi);

            mp[mx - mi].push_back(nums[i]);
        }

        int sum = 0;
        for (int x : mp[hi]) {
            sum += x;
        }
        return sum;
    }
};
