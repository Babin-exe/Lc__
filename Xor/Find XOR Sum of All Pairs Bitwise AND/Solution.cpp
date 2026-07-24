// Problem Link : https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/description/
class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int a = 0, b = 0;
        for (auto& it : arr1)
            a ^= it;
        for (auto& it : arr2)
            b ^= it;
        return a & b;
    }
};
