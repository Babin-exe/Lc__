// Problem Link : https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int value = 0;
        for (int i = 0; i < operations.size(); i++) {
            string s = operations[i];
            if (s[0] == '+' || s[s.length() - 1] == '+')
                value++;
            else if (s[0] == '-' || s[s.length() - 1] == '-')
                value--;
        }
        return value;
    }
};
