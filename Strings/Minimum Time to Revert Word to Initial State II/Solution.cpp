// Problem link : https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-ii/description/
class Solution {
public:
    void makeLPS(string& word, vector<int>& LPS, int n) {
        LPS[0] = 0;
        int i = 1;
        int length = 0;
        while (i < n) {
            if (word[i] == word[length]) {
                length++;
                LPS[i] = length;
                i++;
            } else {
                if (length == 0) {
                    LPS[i] = 0;
                    i++;
                } else {
                    length = LPS[length - 1];
                }
            }
        }
    }

public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.length();
        vector<int> LPS(n, 0);
        makeLPS(word, LPS, n);

        int value = LPS[n - 1];
        while (value > 0 && (n - value) % k != 0) {
            value = LPS[value - 1];
        }
        if (value != 0) {
            return (n - value) / k;
        }
        return ceil(n / (double)k);
    }
};
