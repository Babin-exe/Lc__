// Problem Link :https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/
class Solution {
public:
    int mod = 1e9 + 7;
    long long fact(long long n) {
        long long hehe = 1;
        for (int i = 2; i <= n; i++) {
            hehe = (hehe * i) % mod;
        }
        return hehe;
    }
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0])
                return 0;
        }
        long long count = fact(complexity.size() - 1) % mod;
        return (int)count;
    }
};
