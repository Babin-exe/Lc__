// Problem Link : https://leetcode.com/problems/count-square-sum-triples/description/

class Solution {
public:
    int countTriples(int n) {
        // Brute force approach
        // int count = 0;
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1 ; j <= n; j++) {
        //         for (int k = 1; k <= n; k++) {
        //             if (i * i + j * j == k * k)
        //                 count++;
        //         }
        //     }
        // }
        // return count;

        int count = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int c = sqrt(a * a + b * b);
                if (c * c == a * a + b * b && c <= n)
                    count++;
            }
        }
        return count;
    }
};
