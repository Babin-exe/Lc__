// Problem Link : https://leetcode.com/problems/lexicographical-numbers/


class Solution {
public:
    vector<int> hehe;
public:
    void solve(int num, int n) {
        if (num > n)
            return;
        hehe.push_back(num);
        for (int i = 0; i <= 9; i++) {
            int take = num * 10 + i;
            if (take > n)
                return;
            solve(take, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= 9; i++) {
            solve(i, n);
        }
        return hehe;
    }
};
