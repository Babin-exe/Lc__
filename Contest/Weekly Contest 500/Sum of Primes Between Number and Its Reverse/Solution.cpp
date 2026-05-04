// Problem Link : https://leetcode.com/problems/sum-of-primes-between-number-and-its-reverse/description/



class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int ans = 0;
        int temp = n;
        while (temp != 0) {
            ans = ans * 10 + (temp % 10);
            temp /= 10;
        }

        int mini = min(ans, n);
        int maxi = max(ans, n);
        int fin = 0;

        for (int i = mini; i <= maxi; i++) {
            if (i < 2)
                continue;
            bool isPrime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                fin += i;
            }
        }
        return fin;
    }
};
