// Problem Link : https://leetcode.com/problems/minimum-range-after-sum-operations/description/
class Solution {
public:
    int minRange(int a, int b, int c) {
        if (b > a)
            swap(a, b);
        if (c > a)
            swap(a, c);
        if (c > b)
            swap(c, b);

        int ans = a - c;
        if (b + c < a) ans = min(ans, b);
        

        return ans;
    }
};
