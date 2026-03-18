// Problem Link : https://leetcode.com/problems/count-commas-in-range-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        ans += max(0LL, n - 999);
        ans += max(0LL, n - 999999);
        ans += max(0LL, n - 999999999);
        ans += max(0LL, n - 999999999999LL);
        ans += max(0LL, n - 999999999999999LL);

        return ans;
    }
};
