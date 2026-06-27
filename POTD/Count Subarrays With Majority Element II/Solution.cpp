// Problem Link : https://leetcode.com/problems/count-subarrays-with-majority-element-ii/description/?envType=daily-question&envId=2026-06-27

using ll = long long;
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        ll n = nums.size();
        ll ans = 0;
        ll csum = 0;

        ll other = 0;

        map<int, int> mp;
        mp[0]++;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {

                other += mp[csum];
                csum++;

            } else {

                csum--;
                other -= mp[csum];
            }
            mp[csum]++;
            ans += other;
        }

        return ans;
    }
};
