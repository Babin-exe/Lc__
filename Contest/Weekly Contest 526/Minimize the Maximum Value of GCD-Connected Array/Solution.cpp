// Problem Link : https://leetcode.com/problems/minimize-the-maximum-value-of-gcd-connected-array/description/
using ll = long long;
class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {

        if (value == 1)
            return -1;

        ll p = value;
        for (ll i = 2; i * i <= value; i++) {
            if (value % i == 0) {
                p = i;
                break;
            }
        }

        if (value - p + 2 <= 2LL * index)
            return -1;

        if (index == n - 1)
            return value;

        int r = n - 1 - index;

        ll ans = value + p + (r - 1) * 2;

        return ans;
    }
};
