// Problem Link : https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/?envType=problem-list-v2&envId=maths-m1-arithmetic-basic-reasoning

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {

        sort(begin(arr), end(arr));
        int value = arr[1] - arr[0];
        int n = arr.size();
        for (int i = 2; i < n; i++) {
            if (arr[i] - arr[i - 1] != value)
                return false;
        }
        return true;
    }
};
