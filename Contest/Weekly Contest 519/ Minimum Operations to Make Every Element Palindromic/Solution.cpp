// Problem Link : https://leetcode.com/problems/minimum-operations-to-make-every-element-palindromic/description/
using ll = long long;
class Solution {
public:
    ll makePalindrome(ll x, bool oddLength) {
        ll temp = x;
        if (oddLength)
            x /= 10;

        while (x > 0) {
            temp = (temp * 10) + (x % 10);
            x /= 10;
        }
        return temp;
    }

    void build(vector<ll>& even, vector<ll>& odd) {

        for (int i = 1; i < 100000; i++) {
            ll evenLength = makePalindrome(i, false);

            if (evenLength & 1) {
                odd.push_back(evenLength);
            } else {
                even.push_back(evenLength);
            }

            ll oddLength = makePalindrome(i, true);

            if (oddLength & 1) {
                odd.push_back(oddLength);
            } else {
                even.push_back(oddLength);
            }
        }

        sort(begin(odd), end(odd));
        sort(begin(even), end(even));
    }

    long long minOperations(vector<int>& nums) {
        static vector<ll> even;
        static vector<ll> odd;
        static bool init = false;

        if (!init) {
            build(even, odd);
            init = true;
        }

        ll ans = 0;

        for (auto x : nums) {
            vector<ll>& take = (x & 1) ? odd : even;

            auto it = lower_bound(begin(take), end(take), x);

            ll tt = LLONG_MAX;

            if (it != take.end()) {
                tt = min(tt, *it - x);
            }
            if (it != take.begin()) {
                --it;
                tt = min(tt, x - *it);
            }

            ans += tt / 2;
        }

        return ans;
    }
};
