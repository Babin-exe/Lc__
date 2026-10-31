// Problem Link : https://leetcode.com/problems/binary-digit-score/
class Solution {
public:
    int calculateScore(int a, int b) {

        int s1 = __popcount(a);
        int s2 = __popcount(b);

        if (s1 >= s2) return s1 * s2;
        return s2 / s1;
    }
};
