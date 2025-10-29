// Problem Link : https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/description/

class Solution {
    using ll = long long;

public:
    char kthCharacter(long long k, vector<int>& operations) {

        if (k == 1)
            return 'a';

        ll len = 1;
        int ops = -1;
        ll hehe = -1;

        for (int i = 0; i < operations.size(); i++) {
            len *= 2;

            if (len >= k) {
                ops = operations[i];
                hehe = k - len / 2;
                break;
            }
        }
        char ch = kthCharacter(hehe, operations);
        if (ops == 0)
            return ch;

        return ch == 'z' ? 'a' : ch + 1;
    }
};
