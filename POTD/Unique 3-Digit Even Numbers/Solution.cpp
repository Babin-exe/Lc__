// Problem Link : https://leetcode.com/problems/unique-3-digit-even-numbers/
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> f(10, 0);
        for (auto it : digits)
            f[it]++;
        int ans = 0;

        for (int i = 1; i <= 9; ++i) {
            if (f[i] == 0) {
                continue;
            } f[i]--;

            for (int j = 0; j <= 9; ++j) {
                if (f[j] == 0) {
                    continue;
                } f[j]--;

                for (int k = 0; k <= 8; k += 2) {
                    if (f[k] == 0){
                        continue;
                    } f[k]--;

                    ans++;
                    f[k]++;
                }
                f[j]++;
            }
            f[i]++;
        }
        return ans;
    }
};
