// Problem link : https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/

class Solution {
    int mod = 1e9 + 7;

public:
    int numberOfWays(string corridor) {
        int Scout = 0;
        long long ans = 1;
        int prevIdx = -1;
        int Snum = 0;
        for (int i = 0; i < corridor.length(); i++) {
            if (corridor[i] == 'S') {
                Scout++;
                Snum++;
                if (Scout == 1 && prevIdx != -1) {
                    ans = ans * 1LL * (i - prevIdx) % mod;
                }
                if (Scout == 2) {
                    Scout = 0;
                    prevIdx = i;
                }
            }
        }
        if (Snum == 0 || Snum % 2 != 0)
            return 0;
        return (int)ans;
    }
};
