// Problem Link : https://leetcode.com/contest/weekly-contest-523/problems/three-fibonacci-sum/description/
using ll = long long;
class Solution {
public:
    bool threeFibonacciSum(int n) {
        vector<int> fibo = {0, 1};

        while (true) {
            int s = fibo.size();
            int next =  fibo[s - 1] + fibo[s - 2];
            if (next > n) break;
            fibo.push_back(next);
        }
        
        for (int i = 2; i < fibo.size(); i++) {
            if ((fibo[i] + fibo[i - 1] + fibo[i-2]) == n)return true;
        }

        return false;
    }
}; 
