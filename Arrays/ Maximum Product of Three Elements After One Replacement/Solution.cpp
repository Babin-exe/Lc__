// Problem Link : https://leetcode.com/problems/maximum-product-of-three-elements-after-one-replacement/description/

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long a = LONG_MIN, b = LONG_MIN;
        for (long xx : nums) {
            long x = llabs(xx);
            if (x > a) {
                b = a;
                a = x;
            } else if (b < x) {
                b = x;
            }
        }
        return a * b * 1e5;
    }
};

