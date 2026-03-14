// Problem Link : https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<ll> v(n);
        v[0] = nums[0];

        for (int i = 1; i < n; i++) {

            v[i] = max(v[i - 1], (ll)nums[i]);
        }

        vector<ll> pg(n);

        for (int i = 0; i < n; i++) {
            pg[i] = gcd((ll)nums[i], v[i]);
        }

        sort(begin(pg), end(pg));

        int i = 0;
        int j = pg.size() - 1;
        long long sum = 0;
        while (i < j) {
            sum += (gcd(pg[i], pg[j]));
            i++;
            j--;
        }
        return sum;
    }
};
