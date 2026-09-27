// Problem Link: https://leetcode.com/problems/maximum-equal-adjacent-pairs-after-at-most-one-replacement/description/
class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int ans = 0;

        map<pair<int, int>, int> mp;

        for (int i = 0; i < n - 1; ++i) {
            int x = nums[i];
            int y = nums[i + 1];

            if (x == y) {
                ans++;
            } else {
                if (x < y) swap(x, y);
                mp[{x, y}]++; cnt = max(cnt, mp[{x, y}]);
            }
        }
        return cnt + ans;
    }
};
