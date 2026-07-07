// Problem Link : https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/description/?envType=daily-question&envId=2026-07-07

using ll = long long;
class Solution {
public:
    long long sumAndMultiply(int n) {

        ll sum = 0;
        ll num = 0;
        int a = n;

        ll z = 10;
        while (z--) {
            sum += (a % 10);
            if (a % 10 != 0) {
                num = num * 10 + a % 10;
            }
            a /= 10;
        }
        cout << "Sum is : " << sum << "\n";
        cout << "Num is : " << num << "\n";
        ll t = num;
        ll ans = 0;

        z = 10;

        while (z--) {
            if (t % 10 == 0)
                break;
            ans = ans * 10 + t % 10;
            t /= 10;
        }

        return ans * sum;
    }
};
