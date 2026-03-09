// Problem Link : https://leetcode.com/problems/minimum-operations-to-sort-a-string/description


class Solution {

public:
    int minOperations(string s) {
        int n = s.length();
        char mini = s[0];
        char maxi = s[0];
        int cmin = 0;
        int cmax = 0;
        if (n == 2 && s[0] > s[1])
            return -1;

        if (is_sorted(s.begin(), s.end()))
            return 0;

        for (int i = 0; i < n; i++) {
            if (s[i] > maxi) {
                maxi = s[i];
            }
            if (s[i] < mini) {
                mini = s[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == mini)
                cmin++;
            if (s[i] == maxi)
                cmax++;
        }

        if (s[0] == mini || s[n - 1] == maxi)
            return 1;

        else if (s[0] == maxi && s[n - 1] == mini && (cmin >= 2 || cmax >= 2))
            return 2;

        else if (s[0] == maxi && s[n - 1] == mini)
            return 3;

        return 2;
    }
};
