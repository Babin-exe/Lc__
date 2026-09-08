// Problem Link : https://leetcode.com/problems/count-commas-in-range-ii/description/
using ll = long long;
class Solution {
public:
    long long countCommas(long long n) {

        if (n <= 999)
            return 0;

        int commas = 1;

        ll ans = 0;
        ll lower = 1000;
        
        while (lower <= n) {
            ll upper = min(n, lower * 1000 - 1);
            ll total = upper - lower + 1;
            ans += (total * commas);
            lower *= 1000;
            commas++;
        }

        return ans;
    }
};

//Simpler approach : 
using ll = long long;
class Solution {
public:
    long long countCommas(long long n) {

        if (n <= 999) return 0;
        
        ll l = 1000;
        ll ans = 0;

        while (l <= n) {
            ll count = (n - l + 1);
            l *= 1000;
            ans += count;
        }
        return ans;
    }
};
