// Problem Link : https://leetcode.com/problems/count-k-th-roots-in-a-range/description/
class Solution {
public:
    int countKthRoots(int l, int r, int k) {

        long long L = ceil(pow(l, 1.0 / k) - 1e-9);
        long long R = floor(pow(r, 1.0 / k) + 1e-9);

        return (R >= L) ? (R - L + 1) : 0;
    }
};
