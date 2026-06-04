// Problem Link : https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/description/?envType=daily-question&envId=2026-06-04

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int up = max(num1, num2);
        int ans = 0;
        if (up < 100)
            return 0;
        int down = min(num1, num2);
        down = max(down, 100);

        for (int i = down; i <= up; i++) {
            string st = to_string(i);
            int l = st.length();
            for (int j = 1; j < l - 1; j++) {
                int lf = st[j - 1] - '0';
                int rt = st[j + 1] - '0';
                int curr = st[j] - '0';

                if (curr > lf && curr > rt)
                    ans++;
                else if (curr < lf && curr < rt)
                    ans++;
            }
        }
        return ans;
    }
};
