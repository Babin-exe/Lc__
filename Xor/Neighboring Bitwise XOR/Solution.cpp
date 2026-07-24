// Problem Link : https://leetcode.com/problems/neighboring-bitwise-xor/description/
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {

        int n = derived.size();
        vector<int> a(n);
        a[0] = 0;
        for (int i = 1; i < n; i++) {
            a[i] = a[i - 1] ^ derived[i - 1];
        }
        if (a[n - 1] ^ a[0] == derived[n - 1])
            return true;

        vector<int> b(n);
        b[0] = 1;
        for (int i = 1; i < n; i++) {
            b[i] = b[i - 1] ^ derived[i - 1];
        }

        return b[n - 1] ^ b[0] == derived[n - 1];
    }
};

// Approach 2 : 
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int t = derived[0];
        for (int i = 1; i < n; i++)
            t ^= derived[i];
        return t == 0;
    }
};
